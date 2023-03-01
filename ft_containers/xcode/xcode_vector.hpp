template <bool>
class _LIBCPP_TEMPLATE_VIS __vector_base_common
{
protected:
    _LIBCPP_INLINE_VISIBILITY __vector_base_common() {}
    _LIBCPP_NORETURN void __throw_length_error() const;
    _LIBCPP_NORETURN void __throw_out_of_range() const;
};

template <bool __b>
void
__vector_base_common<__b>::__throw_length_error() const
{
    _VSTD::__throw_length_error("vector");
}

template <bool __b>
void
__vector_base_common<__b>::__throw_out_of_range() const
{
    _VSTD::__throw_out_of_range("vector");
}

_LIBCPP_EXTERN_TEMPLATE(class _LIBCPP_EXTERN_TEMPLATE_TYPE_VIS __vector_base_common<true>)

// ----------------------------------

template <class _Tp, class _Allocator>
class __vector_base
    : protected __vector_base_common<true>
{
public:
    typedef _Allocator                               allocator_type;
    typedef allocator_traits<allocator_type>         __alloc_traits;
    typedef typename __alloc_traits::size_type       size_type;
protected:
    typedef _Tp                                      value_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;
    typedef typename __alloc_traits::difference_type difference_type;
    typedef typename __alloc_traits::pointer         pointer;
    typedef typename __alloc_traits::const_pointer   const_pointer;
    typedef pointer                                  iterator;
    typedef const_pointer                            const_iterator;

    pointer                                         __begin_;
    pointer                                         __end_;
    __compressed_pair<pointer, allocator_type> __end_cap_;

    _LIBCPP_INLINE_VISIBILITY
    allocator_type& __alloc() _NOEXCEPT
        {return __end_cap_.second();}
    _LIBCPP_INLINE_VISIBILITY
    const allocator_type& __alloc() const _NOEXCEPT
        {return __end_cap_.second();}
    _LIBCPP_INLINE_VISIBILITY
    pointer& __end_cap() _NOEXCEPT
        {return __end_cap_.first();}
    _LIBCPP_INLINE_VISIBILITY
    const pointer& __end_cap() const _NOEXCEPT
        {return __end_cap_.first();}

    _LIBCPP_INLINE_VISIBILITY
    __vector_base()
        _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value);
    _LIBCPP_INLINE_VISIBILITY __vector_base(const allocator_type& __a);
    ~__vector_base();

    _LIBCPP_INLINE_VISIBILITY
    void clear() _NOEXCEPT {__destruct_at_end(__begin_);}
    _LIBCPP_INLINE_VISIBILITY
    size_type capacity() const _NOEXCEPT
        {return static_cast<size_type>(__end_cap() - __begin_);}

    _LIBCPP_INLINE_VISIBILITY
    void __destruct_at_end(pointer __new_last) _NOEXCEPT;

    _LIBCPP_INLINE_VISIBILITY
    void __copy_assign_alloc(const __vector_base& __c)
        {__copy_assign_alloc(__c, integral_constant<bool,
                      __alloc_traits::propagate_on_container_copy_assignment::value>());}

private:
    _LIBCPP_INLINE_VISIBILITY
    void __copy_assign_alloc(const __vector_base& __c, true_type)
        {
            if (__alloc() != __c.__alloc())
            {
                clear();
                __alloc_traits::deallocate(__alloc(), __begin_, capacity());
                __begin_ = __end_ = __end_cap() = nullptr;
            }
            __alloc() = __c.__alloc();
        }

    _LIBCPP_INLINE_VISIBILITY
    void __copy_assign_alloc(const __vector_base&, false_type)
        {}
};

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
void
__vector_base<_Tp, _Allocator>::__destruct_at_end(pointer __new_last) _NOEXCEPT
{
    pointer __soon_to_be_end = __end_;
    while (__new_last != __soon_to_be_end)
        __alloc_traits::destroy(__alloc(), _VSTD::__to_address(--__soon_to_be_end));
    __end_ = __new_last;
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
__vector_base<_Tp, _Allocator>::__vector_base()
        _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value)
    : __begin_(nullptr),
      __end_(nullptr),
      __end_cap_(nullptr, __default_init_tag())
{
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
__vector_base<_Tp, _Allocator>::__vector_base(const allocator_type& __a)
    : __begin_(nullptr),
      __end_(nullptr),
      __end_cap_(nullptr, __a)
{
}

template <class _Tp, class _Allocator>
__vector_base<_Tp, _Allocator>::~__vector_base()
{
    if (__begin_ != nullptr)
    {
        clear();
        __alloc_traits::deallocate(__alloc(), __begin_, capacity());
    }
}

// ----------------------------------

template <class _Tp, class _Allocator /* = allocator<_Tp> */>
class _LIBCPP_TEMPLATE_VIS vector
    : private __vector_base<_Tp, _Allocator>
{
private:
    typedef __vector_base<_Tp, _Allocator>           __base;
    typedef allocator<_Tp>                           __default_allocator_type;
public:
    typedef vector                                   __self;
    typedef _Tp                                      value_type;
    typedef _Allocator                               allocator_type;
    typedef typename __base::__alloc_traits          __alloc_traits;
    typedef typename __base::reference               reference;
    typedef typename __base::const_reference         const_reference;
    typedef typename __base::size_type               size_type;
    typedef typename __base::difference_type         difference_type;
    typedef typename __base::pointer                 pointer;
    typedef typename __base::const_pointer           const_pointer;
    typedef __wrap_iter<pointer>                     iterator;
    typedef __wrap_iter<const_pointer>               const_iterator;
    typedef _VSTD::reverse_iterator<iterator>         reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator>   const_reverse_iterator;

    static_assert((is_same<typename allocator_type::value_type, value_type>::value),
                  "Allocator::value_type must be same type as value_type");

    _LIBCPP_INLINE_VISIBILITY
    vector() _NOEXCEPT_(is_nothrow_default_constructible<allocator_type>::value)
        {
        }
    _LIBCPP_INLINE_VISIBILITY explicit vector(const allocator_type& __a)
        _NOEXCEPT_(is_nothrow_copy_constructible<allocator_type>::value)
        : __base(__a)
    {
    }
    explicit vector(size_type __n);
    vector(size_type __n, const value_type& __x);
    vector(size_type __n, const value_type& __x, const allocator_type& __a);
    template <class _InputIterator>
        vector(_InputIterator __first,
               typename enable_if<__is_cpp17_input_iterator  <_InputIterator>::value &&
                                 !__is_cpp17_forward_iterator<_InputIterator>::value &&
                                 is_constructible<
                                    value_type,
                                    typename iterator_traits<_InputIterator>::reference>::value,
                                 _InputIterator>::type __last);
    template <class _InputIterator>
        vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a,
               typename enable_if<__is_cpp17_input_iterator  <_InputIterator>::value &&
                                 !__is_cpp17_forward_iterator<_InputIterator>::value &&
                                 is_constructible<
                                    value_type,
                                    typename iterator_traits<_InputIterator>::reference>::value>::type* = 0);
    template <class _ForwardIterator>
        vector(_ForwardIterator __first,
               typename enable_if<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                                 is_constructible<
                                    value_type,
                                    typename iterator_traits<_ForwardIterator>::reference>::value,
                                 _ForwardIterator>::type __last);
    template <class _ForwardIterator>
        vector(_ForwardIterator __first, _ForwardIterator __last, const allocator_type& __a,
               typename enable_if<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                                 is_constructible<
                                    value_type,
                                    typename iterator_traits<_ForwardIterator>::reference>::value>::type* = 0);

    _LIBCPP_INLINE_VISIBILITY
    ~vector()
    {
        __annotate_delete();
    }

    vector(const vector& __x);
    _LIBCPP_INLINE_VISIBILITY
    vector& operator=(const vector& __x);

    template <class _InputIterator>
        typename enable_if
        <
             __is_cpp17_input_iterator  <_InputIterator>::value &&
            !__is_cpp17_forward_iterator<_InputIterator>::value &&
            is_constructible<
                 value_type,
                 typename iterator_traits<_InputIterator>::reference>::value,
            void
        >::type
        assign(_InputIterator __first, _InputIterator __last);
    template <class _ForwardIterator>
        typename enable_if
        <
            __is_cpp17_forward_iterator<_ForwardIterator>::value &&
            is_constructible<
                 value_type,
                 typename iterator_traits<_ForwardIterator>::reference>::value,
            void
        >::type
        assign(_ForwardIterator __first, _ForwardIterator __last);

    void assign(size_type __n, const_reference __u);

    _LIBCPP_INLINE_VISIBILITY
    allocator_type get_allocator() const _NOEXCEPT
        {return this->__alloc();}

    _LIBCPP_INLINE_VISIBILITY iterator               begin() _NOEXCEPT;
    _LIBCPP_INLINE_VISIBILITY const_iterator         begin()   const _NOEXCEPT;
    _LIBCPP_INLINE_VISIBILITY iterator               end() _NOEXCEPT;
    _LIBCPP_INLINE_VISIBILITY const_iterator         end()     const _NOEXCEPT;

    _LIBCPP_INLINE_VISIBILITY
    reverse_iterator       rbegin() _NOEXCEPT
        {return       reverse_iterator(end());}
    _LIBCPP_INLINE_VISIBILITY
    const_reverse_iterator rbegin()  const _NOEXCEPT
        {return const_reverse_iterator(end());}
    _LIBCPP_INLINE_VISIBILITY
    reverse_iterator       rend() _NOEXCEPT
        {return       reverse_iterator(begin());}
    _LIBCPP_INLINE_VISIBILITY
    const_reverse_iterator rend()    const _NOEXCEPT
        {return const_reverse_iterator(begin());}

    _LIBCPP_INLINE_VISIBILITY
    size_type size() const _NOEXCEPT
        {return static_cast<size_type>(this->__end_ - this->__begin_);}
    _LIBCPP_INLINE_VISIBILITY
    size_type capacity() const _NOEXCEPT
        {return __base::capacity();}
    _LIBCPP_NODISCARD_AFTER_CXX17 _LIBCPP_INLINE_VISIBILITY
    bool empty() const _NOEXCEPT
        {return this->__begin_ == this->__end_;}
    size_type max_size() const _NOEXCEPT;
    void reserve(size_type __n);

    _LIBCPP_INLINE_VISIBILITY reference       operator[](size_type __n) _NOEXCEPT;
    _LIBCPP_INLINE_VISIBILITY const_reference operator[](size_type __n) const _NOEXCEPT;
    reference       at(size_type __n);
    const_reference at(size_type __n) const;

    _LIBCPP_INLINE_VISIBILITY reference       front() _NOEXCEPT
    {
        _LIBCPP_ASSERT(!empty(), "front() called for empty vector");
        return *this->__begin_;
    }
    _LIBCPP_INLINE_VISIBILITY const_reference front() const _NOEXCEPT
    {
        _LIBCPP_ASSERT(!empty(), "front() called for empty vector");
        return *this->__begin_;
    }
    _LIBCPP_INLINE_VISIBILITY reference       back() _NOEXCEPT
    {
        _LIBCPP_ASSERT(!empty(), "back() called for empty vector");
        return *(this->__end_ - 1);
    }
    _LIBCPP_INLINE_VISIBILITY const_reference back()  const _NOEXCEPT
    {
        _LIBCPP_ASSERT(!empty(), "back() called for empty vector");
        return *(this->__end_ - 1);
    }

    _LIBCPP_INLINE_VISIBILITY
    value_type*       data() _NOEXCEPT
        {return _VSTD::__to_address(this->__begin_);}
    _LIBCPP_INLINE_VISIBILITY
    const value_type* data() const _NOEXCEPT
        {return _VSTD::__to_address(this->__begin_);}

    _LIBCPP_INLINE_VISIBILITY
    void __emplace_back(const value_type& __x) { push_back(__x); }

    _LIBCPP_INLINE_VISIBILITY void push_back(const_reference __x);

    _LIBCPP_INLINE_VISIBILITY
    void pop_back();

    iterator insert(const_iterator __position, const_reference __x);

    iterator insert(const_iterator __position, size_type __n, const_reference __x);
    template <class _InputIterator>
        typename enable_if
        <
             __is_cpp17_input_iterator  <_InputIterator>::value &&
            !__is_cpp17_forward_iterator<_InputIterator>::value &&
            is_constructible<
                 value_type,
                 typename iterator_traits<_InputIterator>::reference>::value,
            iterator
        >::type
        insert(const_iterator __position, _InputIterator __first, _InputIterator __last);
    template <class _ForwardIterator>
        typename enable_if
        <
            __is_cpp17_forward_iterator<_ForwardIterator>::value &&
            is_constructible<
                 value_type,
                 typename iterator_traits<_ForwardIterator>::reference>::value,
            iterator
        >::type
        insert(const_iterator __position, _ForwardIterator __first, _ForwardIterator __last);

    _LIBCPP_INLINE_VISIBILITY iterator erase(const_iterator __position);
    iterator erase(const_iterator __first, const_iterator __last);

    _LIBCPP_INLINE_VISIBILITY
    void clear() _NOEXCEPT
    {
        size_type __old_size = size();
        __base::clear();
        __annotate_shrink(__old_size);
        __invalidate_all_iterators();
    }

    void resize(size_type __sz);
    void resize(size_type __sz, const_reference __x);

    void swap(vector&)
        _NOEXCEPT_(!__alloc_traits::propagate_on_container_swap::value ||
                    __is_nothrow_swappable<allocator_type>::value);

    bool __invariants() const;

private:
    _LIBCPP_INLINE_VISIBILITY void __invalidate_all_iterators();
    _LIBCPP_INLINE_VISIBILITY void __invalidate_iterators_past(pointer __new_last);
    void __vallocate(size_type __n);
    void __vdeallocate() _NOEXCEPT;
    _LIBCPP_INLINE_VISIBILITY size_type __recommend(size_type __new_size) const;
    void __construct_at_end(size_type __n);
    _LIBCPP_INLINE_VISIBILITY
    void __construct_at_end(size_type __n, const_reference __x);
    template <class _ForwardIterator>
        typename enable_if
        <
            __is_cpp17_forward_iterator<_ForwardIterator>::value,
            void
        >::type
        __construct_at_end(_ForwardIterator __first, _ForwardIterator __last, size_type __n);
    void __append(size_type __n);
    void __append(size_type __n, const_reference __x);
    _LIBCPP_INLINE_VISIBILITY
    iterator       __make_iter(pointer __p) _NOEXCEPT;
    _LIBCPP_INLINE_VISIBILITY
    const_iterator __make_iter(const_pointer __p) const _NOEXCEPT;
    void __swap_out_circular_buffer(__split_buffer<value_type, allocator_type&>& __v);
    pointer __swap_out_circular_buffer(__split_buffer<value_type, allocator_type&>& __v, pointer __p);
    void __move_range(pointer __from_s, pointer __from_e, pointer __to);
    _LIBCPP_INLINE_VISIBILITY
    void __destruct_at_end(pointer __new_last) _NOEXCEPT
    {
        __invalidate_iterators_past(__new_last);
        size_type __old_size = size();
        __base::__destruct_at_end(__new_last);
        __annotate_shrink(__old_size);
    }

    template <class _Up>
    _LIBCPP_INLINE_VISIBILITY
    inline void __push_back_slow_path(_Up& __x);

    // The following functions are no-ops outside of AddressSanitizer mode.
    // We call annotatations only for the default Allocator because other allocators
    // may not meet the AddressSanitizer alignment constraints.
    // See the documentation for __sanitizer_annotate_contiguous_container for more details.
#ifndef _LIBCPP_HAS_NO_ASAN
    void __annotate_contiguous_container(const void *__beg, const void *__end,
                                         const void *__old_mid,
                                         const void *__new_mid) const
    {

      if (__beg && is_same<allocator_type, __default_allocator_type>::value)
        __sanitizer_annotate_contiguous_container(__beg, __end, __old_mid, __new_mid);
    }
#else
    _LIBCPP_INLINE_VISIBILITY
    void __annotate_contiguous_container(const void*, const void*, const void*,
                                         const void*) const _NOEXCEPT {}
#endif
    _LIBCPP_INLINE_VISIBILITY
    void __annotate_new(size_type __current_size) const _NOEXCEPT {
      __annotate_contiguous_container(data(), data() + capacity(),
                                      data() + capacity(), data() + __current_size);
    }

    _LIBCPP_INLINE_VISIBILITY
    void __annotate_delete() const _NOEXCEPT {
      __annotate_contiguous_container(data(), data() + capacity(),
                                      data() + size(), data() + capacity());
    }

    _LIBCPP_INLINE_VISIBILITY
    void __annotate_increase(size_type __n) const _NOEXCEPT
    {
      __annotate_contiguous_container(data(), data() + capacity(),
                                      data() + size(), data() + size() + __n);
    }

    _LIBCPP_INLINE_VISIBILITY
    void __annotate_shrink(size_type __old_size) const _NOEXCEPT
    {
      __annotate_contiguous_container(data(), data() + capacity(),
                                      data() + __old_size, data() + size());
    }

  struct _ConstructTransaction {
    explicit _ConstructTransaction(vector &__v, size_type __n)
      : __v_(__v),  __pos_(__v.__end_), __new_end_(__v.__end_ + __n) {
#ifndef _LIBCPP_HAS_NO_ASAN
      __v_.__annotate_increase(__n);
#endif
    }
    ~_ConstructTransaction() {
      __v_.__end_ = __pos_;
#ifndef _LIBCPP_HAS_NO_ASAN
      if (__pos_ != __new_end_) {
        __v_.__annotate_shrink(__new_end_ - __v_.__begin_);
      }
#endif
    }

    vector &__v_;
    pointer __pos_;
    const_pointer const __new_end_;

  private:
    _ConstructTransaction(_ConstructTransaction const&) = delete;
    _ConstructTransaction& operator=(_ConstructTransaction const&) = delete;
  };

  template <class ..._Args>
  _LIBCPP_INLINE_VISIBILITY
  void __construct_one_at_end(_Args&& ...__args) {
    _ConstructTransaction __tx(*this, 1);
    __alloc_traits::construct(this->__alloc(), _VSTD::__to_address(__tx.__pos_),
        _VSTD::forward<_Args>(__args)...);
    ++__tx.__pos_;
  }
};

#ifndef _LIBCPP_HAS_NO_DEDUCTION_GUIDES
template<class _InputIterator,
         class _Alloc = typename std::allocator<typename iterator_traits<_InputIterator>::value_type>,
         class = typename enable_if<__is_allocator<_Alloc>::value, void>::type
         >
vector(_InputIterator, _InputIterator)
  -> vector<typename iterator_traits<_InputIterator>::value_type, _Alloc>;

template<class _InputIterator,
         class _Alloc,
         class = typename enable_if<__is_allocator<_Alloc>::value, void>::type
         >
vector(_InputIterator, _InputIterator, _Alloc)
  -> vector<typename iterator_traits<_InputIterator>::value_type, _Alloc>;
#endif

template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::__swap_out_circular_buffer(__split_buffer<value_type, allocator_type&>& __v)
{

    __annotate_delete();
    __alloc_traits::__construct_backward_with_exception_guarantees(
        this->__alloc(), this->__begin_, this->__end_, __v.__begin_);
    _VSTD::swap(this->__begin_, __v.__begin_);
    _VSTD::swap(this->__end_, __v.__end_);
    _VSTD::swap(this->__end_cap(), __v.__end_cap());
    __v.__first_ = __v.__begin_;
    __annotate_new(size());
    __invalidate_all_iterators();
}

template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::pointer
vector<_Tp, _Allocator>::__swap_out_circular_buffer(__split_buffer<value_type, allocator_type&>& __v, pointer __p)
{
    __annotate_delete();
    pointer __r = __v.__begin_;
    __alloc_traits::__construct_backward_with_exception_guarantees(
        this->__alloc(), this->__begin_, __p, __v.__begin_);
    __alloc_traits::__construct_forward_with_exception_guarantees(
        this->__alloc(), __p, this->__end_, __v.__end_);
    _VSTD::swap(this->__begin_, __v.__begin_);
    _VSTD::swap(this->__end_, __v.__end_);
    _VSTD::swap(this->__end_cap(), __v.__end_cap());
    __v.__first_ = __v.__begin_;
    __annotate_new(size());
    __invalidate_all_iterators();
    return __r;
}

//  Allocate space for __n objects
//  throws length_error if __n > max_size()
//  throws (probably bad_alloc) if memory run out
//  Precondition:  __begin_ == __end_ == __end_cap() == 0
//  Precondition:  __n > 0
//  Postcondition:  capacity() == __n
//  Postcondition:  size() == 0
template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::__vallocate(size_type __n)
{
    if (__n > max_size())
        this->__throw_length_error();
    this->__begin_ = this->__end_ = __alloc_traits::allocate(this->__alloc(), __n);
    this->__end_cap() = this->__begin_ + __n;
    __annotate_new(0);
}

template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::__vdeallocate() _NOEXCEPT
{
    if (this->__begin_ != nullptr)
    {
        clear();
        __alloc_traits::deallocate(this->__alloc(), this->__begin_, capacity());
        this->__begin_ = this->__end_ = this->__end_cap() = nullptr;
    }
}

template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::size_type
vector<_Tp, _Allocator>::max_size() const _NOEXCEPT
{
    return _VSTD::min<size_type>(__alloc_traits::max_size(this->__alloc()),
                                 numeric_limits<difference_type>::max());
}

//  Precondition:  __new_size > capacity()
template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
typename vector<_Tp, _Allocator>::size_type
vector<_Tp, _Allocator>::__recommend(size_type __new_size) const
{
    const size_type __ms = max_size();
    if (__new_size > __ms)
        this->__throw_length_error();
    const size_type __cap = capacity();
    if (__cap >= __ms / 2)
        return __ms;
    return _VSTD::max<size_type>(2*__cap, __new_size);
}

//  Default constructs __n objects starting at __end_
//  throws if construction throws
//  Precondition:  __n > 0
//  Precondition:  size() + __n <= capacity()
//  Postcondition:  size() == size() + __n
template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::__construct_at_end(size_type __n)
{
    _ConstructTransaction __tx(*this, __n);
    for (; __tx.__pos_ != __tx.__new_end_; ++__tx.__pos_) {
      __alloc_traits::construct(this->__alloc(), _VSTD::__to_address(__tx.__pos_));
    }
}

//  Copy constructs __n objects starting at __end_ from __x
//  throws if construction throws
//  Precondition:  __n > 0
//  Precondition:  size() + __n <= capacity()
//  Postcondition:  size() == old size() + __n
//  Postcondition:  [i] == __x for all i in [size() - __n, __n)
template <class _Tp, class _Allocator>
inline
void
vector<_Tp, _Allocator>::__construct_at_end(size_type __n, const_reference __x)
{
    _ConstructTransaction __tx(*this, __n);
    for (; __tx.__pos_ != __tx.__new_end_; ++__tx.__pos_) {
        __alloc_traits::construct(this->__alloc(), _VSTD::__to_address(__tx.__pos_), __x);
    }
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator>
typename enable_if
<
    __is_cpp17_forward_iterator<_ForwardIterator>::value,
    void
>::type
vector<_Tp, _Allocator>::__construct_at_end(_ForwardIterator __first, _ForwardIterator __last, size_type __n)
{
    _ConstructTransaction __tx(*this, __n);
    __alloc_traits::__construct_range_forward(this->__alloc(), __first, __last, __tx.__pos_);
}

//  Default constructs __n objects starting at __end_
//  throws if construction throws
//  Postcondition:  size() == size() + __n
//  Exception safety: strong.
template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::__append(size_type __n)
{
    if (static_cast<size_type>(this->__end_cap() - this->__end_) >= __n)
        this->__construct_at_end(__n);
    else
    {
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__recommend(size() + __n), size(), __a);
        __v.__construct_at_end(__n);
        __swap_out_circular_buffer(__v);
    }
}

//  Default constructs __n objects starting at __end_
//  throws if construction throws
//  Postcondition:  size() == size() + __n
//  Exception safety: strong.
template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::__append(size_type __n, const_reference __x)
{
    if (static_cast<size_type>(this->__end_cap() - this->__end_) >= __n)
        this->__construct_at_end(__n, __x);
    else
    {
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__recommend(size() + __n), size(), __a);
        __v.__construct_at_end(__n, __x);
        __swap_out_circular_buffer(__v);
    }
}

template <class _Tp, class _Allocator>
vector<_Tp, _Allocator>::vector(size_type __n)
{
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n);
    }
}

template <class _Tp, class _Allocator>
vector<_Tp, _Allocator>::vector(size_type __n, const value_type& __x)
{
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n, __x);
    }
}

template <class _Tp, class _Allocator>
vector<_Tp, _Allocator>::vector(size_type __n, const value_type& __x, const allocator_type& __a)
    : __base(__a)
{
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n, __x);
    }
}

template <class _Tp, class _Allocator>
template <class _InputIterator>
vector<_Tp, _Allocator>::vector(_InputIterator __first,
       typename enable_if<__is_cpp17_input_iterator  <_InputIterator>::value &&
                         !__is_cpp17_forward_iterator<_InputIterator>::value &&
                         is_constructible<
                            value_type,
                            typename iterator_traits<_InputIterator>::reference>::value,
                          _InputIterator>::type __last)
{
    for (; __first != __last; ++__first)
        __emplace_back(*__first);
}

template <class _Tp, class _Allocator>
template <class _InputIterator>
vector<_Tp, _Allocator>::vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a,
       typename enable_if<__is_cpp17_input_iterator  <_InputIterator>::value &&
                         !__is_cpp17_forward_iterator<_InputIterator>::value &&
                         is_constructible<
                            value_type,
                            typename iterator_traits<_InputIterator>::reference>::value>::type*)
    : __base(__a)
{
    for (; __first != __last; ++__first)
        __emplace_back(*__first);
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator>
vector<_Tp, _Allocator>::vector(_ForwardIterator __first,
                                typename enable_if<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                                is_constructible<
                                   value_type,
                                   typename iterator_traits<_ForwardIterator>::reference>::value,
                                                   _ForwardIterator>::type __last)
{
    size_type __n = static_cast<size_type>(_VSTD::distance(__first, __last));
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__first, __last, __n);
    }
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator>
vector<_Tp, _Allocator>::vector(_ForwardIterator __first, _ForwardIterator __last, const allocator_type& __a,
                                typename enable_if<__is_cpp17_forward_iterator<_ForwardIterator>::value &&
                                is_constructible<
                                   value_type,
                                   typename iterator_traits<_ForwardIterator>::reference>::value>::type*)
    : __base(__a)
{
    size_type __n = static_cast<size_type>(_VSTD::distance(__first, __last));
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__first, __last, __n);
    }
}

template <class _Tp, class _Allocator>
vector<_Tp, _Allocator>::vector(const vector& __x)
    : __base(__alloc_traits::select_on_container_copy_construction(__x.__alloc()))
{
    size_type __n = __x.size();
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__x.__begin_, __x.__end_, __n);
    }
}

template <class _Tp, class _Allocator>
vector<_Tp, _Allocator>::vector(const vector& __x, const allocator_type& __a)
    : __base(__a)
{
    size_type __n = __x.size();
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__x.__begin_, __x.__end_, __n);
    }
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
vector<_Tp, _Allocator>&
vector<_Tp, _Allocator>::operator=(const vector& __x)
{
    if (this != &__x)
    {
        __base::__copy_assign_alloc(__x);
        assign(__x.__begin_, __x.__end_);
    }
    return *this;
}

template <class _Tp, class _Allocator>
template <class _InputIterator>
typename enable_if
<
     __is_cpp17_input_iterator  <_InputIterator>::value &&
    !__is_cpp17_forward_iterator<_InputIterator>::value &&
    is_constructible<
       _Tp,
       typename iterator_traits<_InputIterator>::reference>::value,
    void
>::type
vector<_Tp, _Allocator>::assign(_InputIterator __first, _InputIterator __last)
{
    clear();
    for (; __first != __last; ++__first)
        __emplace_back(*__first);
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator>
typename enable_if
<
    __is_cpp17_forward_iterator<_ForwardIterator>::value &&
    is_constructible<
       _Tp,
       typename iterator_traits<_ForwardIterator>::reference>::value,
    void
>::type
vector<_Tp, _Allocator>::assign(_ForwardIterator __first, _ForwardIterator __last)
{
    size_type __new_size = static_cast<size_type>(_VSTD::distance(__first, __last));
    if (__new_size <= capacity())
    {
        _ForwardIterator __mid = __last;
        bool __growing = false;
        if (__new_size > size())
        {
            __growing = true;
            __mid =  __first;
            _VSTD::advance(__mid, size());
        }
        pointer __m = _VSTD::copy(__first, __mid, this->__begin_);
        if (__growing)
            __construct_at_end(__mid, __last, __new_size - size());
        else
            this->__destruct_at_end(__m);
    }
    else
    {
        __vdeallocate();
        __vallocate(__recommend(__new_size));
        __construct_at_end(__first, __last, __new_size);
    }
    __invalidate_all_iterators();
}

template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::assign(size_type __n, const_reference __u)
{
    if (__n <= capacity())
    {
        size_type __s = size();
        _VSTD::fill_n(this->__begin_, _VSTD::min(__n, __s), __u);
        if (__n > __s)
            __construct_at_end(__n - __s, __u);
        else
            this->__destruct_at_end(this->__begin_ + __n);
    }
    else
    {
        __vdeallocate();
        __vallocate(__recommend(static_cast<size_type>(__n)));
        __construct_at_end(__n, __u);
    }
    __invalidate_all_iterators();
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::__make_iter(pointer __p) _NOEXCEPT
{
    return iterator(__p);
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
typename vector<_Tp, _Allocator>::const_iterator
vector<_Tp, _Allocator>::__make_iter(const_pointer __p) const _NOEXCEPT
{
    return const_iterator(__p);
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::begin() _NOEXCEPT
{
    return __make_iter(this->__begin_);
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
typename vector<_Tp, _Allocator>::const_iterator
vector<_Tp, _Allocator>::begin() const _NOEXCEPT
{
    return __make_iter(this->__begin_);
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::end() _NOEXCEPT
{
    return __make_iter(this->__end_);
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
typename vector<_Tp, _Allocator>::const_iterator
vector<_Tp, _Allocator>::end() const _NOEXCEPT
{
    return __make_iter(this->__end_);
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
typename vector<_Tp, _Allocator>::reference
vector<_Tp, _Allocator>::operator[](size_type __n) _NOEXCEPT
{
    _LIBCPP_ASSERT(__n < size(), "vector[] index out of bounds");
    return this->__begin_[__n];
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
typename vector<_Tp, _Allocator>::const_reference
vector<_Tp, _Allocator>::operator[](size_type __n) const _NOEXCEPT
{
    _LIBCPP_ASSERT(__n < size(), "vector[] index out of bounds");
    return this->__begin_[__n];
}

template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::reference
vector<_Tp, _Allocator>::at(size_type __n)
{
    if (__n >= size())
        this->__throw_out_of_range();
    return this->__begin_[__n];
}

template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::const_reference
vector<_Tp, _Allocator>::at(size_type __n) const
{
    if (__n >= size())
        this->__throw_out_of_range();
    return this->__begin_[__n];
}

template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::reserve(size_type __n)
{
    if (__n > capacity())
    {
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__n, size(), __a);
        __swap_out_circular_buffer(__v);
    }
}

template <class _Tp, class _Allocator>
template <class _Up>
void
vector<_Tp, _Allocator>::__push_back_slow_path(_Up& __x)
{
    allocator_type& __a = this->__alloc();
    __split_buffer<value_type, allocator_type&> __v(__recommend(size() + 1), size(), __a);
    // __v.push_back(_VSTD::forward<_Up>(__x));
    __alloc_traits::construct(__a, _VSTD::__to_address(__v.__end_), _VSTD::forward<_Up>(__x));
    __v.__end_++;
    __swap_out_circular_buffer(__v);
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
void
vector<_Tp, _Allocator>::push_back(const_reference __x)
{
    if (this->__end_ != this->__end_cap())
    {
        __construct_one_at_end(__x);
    }
    else
        __push_back_slow_path(__x);
}

template <class _Tp, class _Allocator>
inline
void
vector<_Tp, _Allocator>::pop_back()
{
    _LIBCPP_ASSERT(!empty(), "vector::pop_back called for empty vector");
    this->__destruct_at_end(this->__end_ - 1);
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::erase(const_iterator __position)
{
    _LIBCPP_ASSERT(__position != end(),
        "vector::erase(iterator) called with a non-dereferenceable iterator");
    difference_type __ps = __position - cbegin();
    pointer __p = this->__begin_ + __ps;
    this->__destruct_at_end(_VSTD::move(__p + 1, this->__end_, __p));
    this->__invalidate_iterators_past(__p-1);
    iterator __r = __make_iter(__p);
    return __r;
}

template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::erase(const_iterator __first, const_iterator __last)
{
    _LIBCPP_ASSERT(__first <= __last, "vector::erase(first, last) called with invalid range");
    pointer __p = this->__begin_ + (__first - begin());
    if (__first != __last) {
        this->__destruct_at_end(_VSTD::move(__p + (__last - __first), this->__end_, __p));
        this->__invalidate_iterators_past(__p - 1);
    }
    iterator __r = __make_iter(__p);
    return __r;
}

template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::__move_range(pointer __from_s, pointer __from_e, pointer __to)
{
    pointer __old_last = this->__end_;
    difference_type __n = __old_last - __to;
    {
      pointer __i = __from_s + __n;
      _ConstructTransaction __tx(*this, __from_e - __i);
      for (; __i < __from_e; ++__i, ++__tx.__pos_) {
          __alloc_traits::construct(this->__alloc(),
                                    _VSTD::__to_address(__tx.__pos_),
                                    _VSTD::move(*__i));
      }
    }
    _VSTD::move_backward(__from_s, __from_s + __n, __old_last);
}

template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::insert(const_iterator __position, const_reference __x)
{
    pointer __p = this->__begin_ + (__position - begin());
    if (this->__end_ < this->__end_cap())
    {
        if (__p == this->__end_)
        {
            __construct_one_at_end(__x);
        }
        else
        {
            __move_range(__p, this->__end_, __p + 1);
            const_pointer __xr = pointer_traits<const_pointer>::pointer_to(__x);
            if (__p <= __xr && __xr < this->__end_)
                ++__xr;
            *__p = *__xr;
        }
    }
    else
    {
        allocator_type& __a = this->__alloc();
        __split_buffer<value_type, allocator_type&> __v(__recommend(size() + 1), __p - this->__begin_, __a);
        __v.push_back(__x);
        __p = __swap_out_circular_buffer(__v, __p);
    }
    return __make_iter(__p);
}

template <class _Tp, class _Allocator>
typename vector<_Tp, _Allocator>::iterator
vector<_Tp, _Allocator>::insert(const_iterator __position, size_type __n, const_reference __x)
{
    pointer __p = this->__begin_ + (__position - begin());
    if (__n > 0)
    {
        if (__n <= static_cast<size_type>(this->__end_cap() - this->__end_))
        {
            size_type __old_n = __n;
            pointer __old_last = this->__end_;
            if (__n > static_cast<size_type>(this->__end_ - __p))
            {
                size_type __cx = __n - (this->__end_ - __p);
                __construct_at_end(__cx, __x);
                __n -= __cx;
            }
            if (__n > 0)
            {
                __move_range(__p, __old_last, __p + __old_n);
                const_pointer __xr = pointer_traits<const_pointer>::pointer_to(__x);
                if (__p <= __xr && __xr < this->__end_)
                    __xr += __old_n;
                _VSTD::fill_n(__p, __n, *__xr);
            }
        }
        else
        {
            allocator_type& __a = this->__alloc();
            __split_buffer<value_type, allocator_type&> __v(__recommend(size() + __n), __p - this->__begin_, __a);
            __v.__construct_at_end(__n, __x);
            __p = __swap_out_circular_buffer(__v, __p);
        }
    }
    return __make_iter(__p);
}

template <class _Tp, class _Allocator>
template <class _InputIterator>
typename enable_if
<
     __is_cpp17_input_iterator  <_InputIterator>::value &&
    !__is_cpp17_forward_iterator<_InputIterator>::value &&
    is_constructible<
       _Tp,
       typename iterator_traits<_InputIterator>::reference>::value,
    typename vector<_Tp, _Allocator>::iterator
>::type
vector<_Tp, _Allocator>::insert(const_iterator __position, _InputIterator __first, _InputIterator __last)
{
    difference_type __off = __position - begin();
    pointer __p = this->__begin_ + __off;
    allocator_type& __a = this->__alloc();
    pointer __old_last = this->__end_;
    for (; this->__end_ != this->__end_cap() && __first != __last; ++__first)
    {
        __construct_one_at_end(*__first);
    }
    __split_buffer<value_type, allocator_type&> __v(__a);
    if (__first != __last)
    {
#ifndef _LIBCPP_NO_EXCEPTIONS
        try
        {
#endif  // _LIBCPP_NO_EXCEPTIONS
            __v.__construct_at_end(__first, __last);
            difference_type __old_size = __old_last - this->__begin_;
            difference_type __old_p = __p - this->__begin_;
            reserve(__recommend(size() + __v.size()));
            __p = this->__begin_ + __old_p;
            __old_last = this->__begin_ + __old_size;
#ifndef _LIBCPP_NO_EXCEPTIONS
        }
        catch (...)
        {
            erase(__make_iter(__old_last), end());
            throw;
        }
#endif  // _LIBCPP_NO_EXCEPTIONS
    }
    __p = _VSTD::rotate(__p, __old_last, this->__end_);
    insert(__make_iter(__p), make_move_iterator(__v.begin()),
                                    make_move_iterator(__v.end()));
    return begin() + __off;
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator>
typename enable_if
<
    __is_cpp17_forward_iterator<_ForwardIterator>::value &&
    is_constructible<
       _Tp,
       typename iterator_traits<_ForwardIterator>::reference>::value,
    typename vector<_Tp, _Allocator>::iterator
>::type
vector<_Tp, _Allocator>::insert(const_iterator __position, _ForwardIterator __first, _ForwardIterator __last)
{
    pointer __p = this->__begin_ + (__position - begin());
    difference_type __n = _VSTD::distance(__first, __last);
    if (__n > 0)
    {
        if (__n <= this->__end_cap() - this->__end_)
        {
            size_type __old_n = __n;
            pointer __old_last = this->__end_;
            _ForwardIterator __m = __last;
            difference_type __dx = this->__end_ - __p;
            if (__n > __dx)
            {
                __m = __first;
                difference_type __diff = this->__end_ - __p;
                _VSTD::advance(__m, __diff);
                __construct_at_end(__m, __last, __n - __diff);
                __n = __dx;
            }
            if (__n > 0)
            {
                __move_range(__p, __old_last, __p + __old_n);
                _VSTD::copy(__first, __m, __p);
            }
        }
        else
        {
            allocator_type& __a = this->__alloc();
            __split_buffer<value_type, allocator_type&> __v(__recommend(size() + __n), __p - this->__begin_, __a);
            __v.__construct_at_end(__first, __last);
            __p = __swap_out_circular_buffer(__v, __p);
        }
    }
    return __make_iter(__p);
}

template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::resize(size_type __sz)
{
    size_type __cs = size();
    if (__cs < __sz)
        this->__append(__sz - __cs);
    else if (__cs > __sz)
        this->__destruct_at_end(this->__begin_ + __sz);
}

template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::resize(size_type __sz, const_reference __x)
{
    size_type __cs = size();
    if (__cs < __sz)
        this->__append(__sz - __cs, __x);
    else if (__cs > __sz)
        this->__destruct_at_end(this->__begin_ + __sz);
}

template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::swap(vector& __x)
    _NOEXCEPT_(!__alloc_traits::propagate_on_container_swap::value ||
                __is_nothrow_swappable<allocator_type>::value)
{
    _LIBCPP_ASSERT(__alloc_traits::propagate_on_container_swap::value ||
                   this->__alloc() == __x.__alloc(),
                   "vector::swap: Either propagate_on_container_swap must be true"
                   " or the allocators must compare equal");
    _VSTD::swap(this->__begin_, __x.__begin_);
    _VSTD::swap(this->__end_, __x.__end_);
    _VSTD::swap(this->__end_cap(), __x.__end_cap());
    __swap_allocator(this->__alloc(), __x.__alloc(),
        integral_constant<bool,__alloc_traits::propagate_on_container_swap::value>());
}

template <class _Tp, class _Allocator>
bool
vector<_Tp, _Allocator>::__invariants() const
{
    if (this->__begin_ == nullptr)
    {
        if (this->__end_ != nullptr || this->__end_cap() != nullptr)
            return false;
    }
    else
    {
        if (this->__begin_ > this->__end_)
            return false;
        if (this->__begin_ == this->__end_cap())
            return false;
        if (this->__end_ > this->__end_cap())
            return false;
    }
    return true;
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
void
vector<_Tp, _Allocator>::__invalidate_all_iterators()
{
}

template <class _Tp, class _Allocator>
inline _LIBCPP_INLINE_VISIBILITY
void
vector<_Tp, _Allocator>::__invalidate_iterators_past(pointer __new_last) {
  ((void)__new_last);
}
