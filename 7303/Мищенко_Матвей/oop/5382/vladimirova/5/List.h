#pragma once

template <class Type>
struct node
{
	Type value;
	node* next;
	node* prev;

	node(const Type& value, node<Type>* next, node<Type>* prev)
		: value(value), next(next), prev(prev)
	{
	}
};

template <class Type>
class list; //forward declaration

template <class Type>
class list_iterator
{
public:
	typedef ptrdiff_t difference_type;
	typedef Type value_type;
	typedef Type* pointer;
	typedef Type& reference;
	typedef size_t size_type;
	typedef std::forward_iterator_tag iterator_category;

	list_iterator()
		: m_node(NULL)
	{
	}

	list_iterator(const list_iterator& other)
		: m_node(other.m_node)
	{
	}

	list_iterator& operator = (const list_iterator& other)
	{

		m_node = other.m_node;
		return *this;
	}

	bool operator == (const list_iterator& other) const
	{
		return m_node == other.m_node;
	}

	bool operator != (const list_iterator& other) const
	{
		return m_node != other.m_node;
	}

	reference operator * ()
	{
		return m_node->value;
	}

	pointer operator -> ()
	{
		return &(m_node->value);
	}

	list_iterator& operator ++ ()
	{
		m_node = m_node->next;
		return *this;
	}

	list_iterator operator ++ (int)
	{
		list_iterator help(*this);
		++(*this);
		return help;
	}

private:
	friend class list<Type>;

	list_iterator(node<Type>* p)
		: m_node(p)
	{
	}

	node<Type>* m_node;
};

template <class Type>
class list
{
public:
	typedef Type value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef list_iterator<Type> iterator;

	list()
		: m_head(nullptr), m_tail(nullptr)
	{
	}

	list(const list& other)
	{
		// implement this
		m_head = m_tail = nullptr;
		const node<Type>* tmp = other.get_head();
		node<Type>* help = const_cast<node<Type>*>(tmp);
		while (help) {
			push_back(help->value);
			help = help->next;
		}
	}

	list(list&& other)
		:m_head(other.m_head), m_tail(other.m_tail)
	{
		other.m_head = other.m_tail = nullptr;
	}

	list& operator= (const list& other)
	{
		if (this != &other) {

			clear();

			const node<Type>* tmp = other.get_head();
			node<Type>* help = const_cast<node<Type>*>(tmp);
			while (help) {
				push_back(help->value);
				help = help->next;
			}
		}
		return *this;

	}

	const node<Type>* get_head() const {
		return this->m_head;
	}

	~list()
	{
		clear();
	}

	iterator begin()
	{
		return iterator(m_head);
	}

	iterator end()
	{
		return iterator();
	}

	void push_back(const value_type& value)
	{
		{
			node<Type> *tmp = new node<Type>(value, nullptr, nullptr);
			if (m_head == nullptr)
			{
				m_head = m_tail = tmp;
			}
			else
			{
				tmp->prev = m_tail;
				m_tail->next = tmp;
				m_tail = tmp;
			}
		}
	}


	void push_front(const value_type& value)
	{
		{
			node<Type> *tmp = new node<Type>(value, nullptr, nullptr);

			if (m_head == nullptr)
			{
				m_head = m_tail = tmp;
			}
			else
			{
				tmp->next = m_head;
				m_head->prev = tmp;
				m_head = tmp;
			}
		}
	}

	reference front()
	{
		return m_head->value;
	}

	const_reference front() const
	{
		return m_head->value;
	}

	reference back()
	{
		return m_tail->value;
	}

	const_reference back() const
	{
		return m_tail->value;
	}

	void pop_front()
	{
		if (m_head == m_tail)
		{
			node<Type>* m_help = m_head;
			m_head = m_tail = nullptr;
			delete m_help;
		}
		else
		{
			node<Type>* m_help = m_head;
			m_head = m_head->next;
			m_head->prev = nullptr;
			delete m_help;
		}
	}

	void pop_back()
	{
		if (m_head == m_tail)
		{
			node<Type>* m_help = m_head;
			m_head = m_tail = nullptr;
			delete m_help;
		}
		else
		{
			node<Type>* m_help = m_tail;
			m_tail = m_tail->prev;
			m_tail->next = nullptr;
			delete m_help;
		}
	}

	void clear()
	{
		while (m_head)
		{
			m_tail = m_head->next;
			delete m_head;
			m_head = m_tail;
		}
	}

	iterator insert(iterator pos, const Type& value)
	{
		if (pos.m_node == m_head)
		{
			push_front(value);
			return iterator(m_head);
		}

		if (pos.m_node == nullptr)
		{
			push_back(value);
			return iterator(m_tail);
		}

		else
		{
			node<Type> *tmp = new node<Type>(value, nullptr, nullptr);
			tmp->next = pos.m_node;
			tmp->prev = pos.m_node->prev;
			pos.m_node->prev->next = tmp;
			pos.m_node->prev = tmp;
			pos.m_node = tmp;
			return iterator(tmp);
		}
	}


	iterator erase(iterator pos)
	{
		if (pos.m_node == m_head)
		{
			pop_front();
			return iterator(m_head);
		}

		if (pos.m_node == m_tail)
		{
			pop_back();
			return iterator(m_tail);
		}

		else
		{
			pos.m_node->next->prev = pos.m_node->prev;
			pos.m_node->prev->next = pos.m_node->next;
			iterator help(pos.m_node->next);
			delete pos.m_node;
			return help;
		}
	}
private:
	//your private functions

	node<Type>* m_head;
	node<Type>* m_tail;
};