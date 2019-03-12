#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <stdexcept>
#include <algorithm>
#include <cstddef>
#include <initializer_list>
namespace my_impl
{
	template <typename Type>
	class vector
	{
	public:
		typedef Type* iterator;
		typedef const Type* const_iterator;

		typedef Type value_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;

		//������ size_t � ptrdiff_t ������ ��������� � �������� ���������.
		//�� ���� ������� ������ ��� ���� ������� ������������ � ��������
		//�������� ������� ��������, ��� �������� ���������� � ���������� � �����������.
		typedef std::ptrdiff_t difference_type; //��������
		typedef size_t size_type; //�����������

								  //������� ��������� � count ������������ T, �������������������
								  //������������� ��-���������. ��� ���� ����������� �� ����������.
		explicit vector(size_t count = 0) : m_first(new value_type[count]), m_last(m_first + count) {}

		//������� ��������� � ���������� ��������� [first, last).
		template <typename InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			difference_type _size = last - first;
			if (_size) {
				m_first = new value_type[_size];
				m_last = m_first + _size;
				std::copy(first, last, m_first);
			}
			else m_first = m_last = nullptr;
		}

		//������� ��������� � ���������� ������ ������������� init.
		vector(std::initializer_list<Type> init)
		{
			size_type _size = init.size();
			if (_size) {
				m_first = new value_type[_size];
				m_last = m_first + _size;
				std::copy(init.begin(), init.end(), m_first);
			}
		}

		//����������� �����������. ������� ��������� � ������ ����������� other.
		vector(const vector& other)
		{
			size_type _size = other.size();
			if (_size) {
				m_first = new value_type[_size];
				m_last = m_first + _size;
				std::copy(other.m_first, other.m_last, m_first);
			}
		}

		//����������� �����������. ������� ��������� � ���������� other ���� ����������� ������.
		vector(vector&& other) : m_first(other.m_first), m_last(other.m_last)
		{
			other.m_first = other.m_last = nullptr;
		}

		~vector()
		{
			delete[] m_first;
		}

		//assignment operators
		//�������� ���������� ������ ����������� other
		vector& operator=(const vector& other)
		{
			if (this != &other)
				if (size() == other.size())
					std::copy(other.begin(), other.end(), m_first);
				else {
					this -> ~vector();
					new (this) vector(other);
				}
				return *this;
		}

		//������ � other ������������ �� other � ���� ���������
		vector& operator=(vector&& other)
		{
			if (this != &other) {
				delete[] m_first;
				m_first = other.m_first;
				m_last = other.m_last;
				other.m_first = other.m_last = nullptr;
			}
			return *this;
		}

		// assign method
		// �������� ���������� ������� ���, ��� � ��������� [first, last)
		template <typename InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			if (!empty())
				this -> ~vector();
			new (this) vector(first, last);
		}


		/*�������� ������ ����������, ����� ��������� count ���������.
		���� ������� ������ ������, ��� count, �������������� �������� �����������
		���� ������� ������ ������ count, ��������� �������� � �� ������ �������� count.*/
		void resize(size_t count)
		{
			if (count != size()) {
				if (count) {
					value_type* tmp = new value_type[count];

					if (count > size()) std::copy(m_first, m_last, tmp);
					else std::copy(m_first, m_first + count, tmp);

					delete[] m_first;
					m_first = tmp;
					m_last = tmp + count;
				}
				else {
					delete[] m_first;
					m_last = m_first = nullptr;
				}
			}
		}

		//erase methods
		//������� ������� � ������� pos.
		iterator erase(const_iterator pos)
		{
			difference_type diff = pos - m_first;
			std::rotate(m_first + diff, m_first + diff + 1, m_last); //(pos, pos+1, m_last)
			resize(m_last - m_first - 1);
			return m_first + diff;
		}

		//������� �������� � ��������� [first; last).
		iterator erase(const_iterator first, const_iterator last)
		{
			difference_type diff = first - m_first;
			difference_type _size = last - first;
			std::rotate(m_first + diff, m_first + diff + _size, m_last); //(first, last, m_last)
			resize(m_last - m_first - _size);
			return m_first + diff;
		}


		//insert methods
		//��������� value ����� ���������, �� ������� ��������� pos
		iterator insert(const_iterator pos, const_reference value)
		{
			size_type count = size() + 1;
			difference_type necessary_position = pos - m_first;
			value_type* tmp = new value_type[count];

			//��������� �� ������� � ������� pos
			iterator our_element_it = &m_first[necessary_position];
			//�������� �� ������� � ������� ���������, ��������� ����� �� ��������� ������������� ���������
			iterator _it = std::copy(m_first, our_element_it, tmp);

			*(_it) = value;
			std::copy(our_element_it, m_last, _it + 1);

			if (m_first)
				this -> ~vector();
			new (this) vector(count);
			std::copy(tmp, tmp + count, m_first);
			delete[] tmp;

			return m_first + necessary_position; //��������, ����������� �� ����������� value
		}


		// ��������� �������� �� ��������� [first, last) ����� ���������, �� ������� ��������� pos.
		template <typename InputIterator>
		iterator insert(const_iterator pos, InputIterator first, InputIterator last)
		{
			difference_type added_size = last - first;
			size_type count = size() + added_size;
			difference_type necessary_position = pos - m_first;
			value_type* tmp = new value_type[count];

			std::copy(m_first, m_first + necessary_position, tmp);
			std::copy(first, last, tmp + necessary_position);
			std::copy(m_first + necessary_position, m_last, tmp + necessary_position + added_size);

			if (m_first)
				this -> ~vector();
			new (this) vector(count);
			std::copy(tmp, tmp + count, m_first);
			delete[] tmp;

			return m_first + necessary_position; //��������, ����������� �� ������ ����������� �������, ��� pos ���� first==last
		}

		//push_back methods
		void push_back(const value_type& value)
		{
			vector<value_type> tmp;
			tmp = *this;
			if (!empty())
				this -> ~vector();
			new (this) vector(tmp.size() + 1);
			std::copy(tmp.begin(), tmp.end(), m_first);
			m_first[tmp.size()] = value;
		}

		//at methods
		reference at(size_t pos) { return checkIndexAndGet(pos); }

		const_reference at(size_t pos) const { return checkIndexAndGet(pos); }

		//[] operators
		reference operator[](size_t pos) { return m_first[pos]; }

		const_reference operator[](size_t pos) const { return m_first[pos]; }

		//*begin methods
		iterator begin() { return m_first; }

		const_iterator begin() const { return m_first; }

		//*end methods
		iterator end() { return m_last; }

		const_iterator end() const { return m_last; }

		//size method
		size_t size() const { return m_last - m_first; }

		//empty method
		bool empty() const { return m_first == m_last; }

	private:
		reference checkIndexAndGet(size_t pos) const
		{
			if (pos >= size())
			{
                throw std::out_of_range("out of range");
			}
			return m_first[pos];
		}


	private:
		iterator m_first;
		iterator m_last;
	};
} //namespace my_impl

#endif //MYVECTOR_H
