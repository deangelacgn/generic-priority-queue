#include "pq.h"

template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::fix_heap( size_type item_idx )
{
	size_type top_value = item_idx;

	if(((2 * item_idx + 1) < m_length) && m_cmp(m_data[2 * item_idx + 1], m_data[top_value]))
	{
		top_value = 2 * item_idx + 1;
	}

	if(((2 * item_idx + 2) < m_length) && m_cmp(m_data[2 * item_idx + 2], m_data[top_value]))
	{
		top_value = 2 * item_idx + 2;
	}

	if(top_value != item_idx)
	{
		//faz o swap das posicoes
		std::swap(m_data[item_idx], m_data[top_value]);

		fix_heap(top_value);
	}

}


template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::move_up( size_type item_idx )
{
	// enquanto o pai for maior ou menor do que o filho
	while(m_cmp(m_data[item_idx], m_data[(item_idx - 1)/2]) && item_idx > 0)
	{
	  // swap entre o pai e o filho
	  std::swap(m_data[(item_idx - 1)/2], m_data[item_idx]);

	  item_idx = (item_idx - 1)/2;
	}
}


template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::reserve( size_type new_cap )
{

	ValueType * temp =  new ValueType[new_cap];

	for(size_t i = 0; i < new_cap; i++)
	{
	  temp[i] = m_data[i];
	}

	m_data.reset( temp );

	m_capacity = new_cap;
}


template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::push( const_reference x )
{
	//verifica se o array suporta a insercao
	if(m_length >= m_capacity)
	{
		reserve(2 * m_capacity);
	}

	if(m_sorted == false)
	{
		for(auto i = m_length/2; i > 0; i--)
		{
			fix_heap(i-1);
		}

		m_sorted = true;
	}

	m_data[m_length] = x;
	
	if(m_cmp(m_data[m_length], m_data[(m_length - 1)/2]) && m_length > 0 ) 
	{
		move_up(m_length);
	}

	m_length++;
}


template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::toss( const ValueType & x )
{
	if(m_length >= m_capacity)
	{
		reserve(2 * m_capacity);
	}

	m_data[m_length] = x;

	//Enquanto o pai for maior/menor do que o filho
	if(m_cmp(m_data[m_length], m_data[(m_length - 1)/2]) && (m_sorted == true ) && m_length > 0) 
	{
		m_sorted = false;
	}

	m_length ++;
}

template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::pop()
{
	//Reorganiza a heap antes de fazer o pop
	if(m_sorted == false)
	{
		for(auto i = m_length/2; i > 0; i--)
		{
			fix_heap(i-1);
		}

		m_sorted = true;
	}

	std::swap(m_data[0], m_data[m_length-1]);

	m_length --;

	//Move o elemento que tá na raiz pra baixo, reorganizando a heap(substitui o move_down)
	fix_heap(0);

}


template < typename ValueType, typename Compare >
typename PQ< ValueType, Compare >::const_reference PQ< ValueType, Compare >::top( void ) 
{ 
	//Reorganiza a heeap antes de liberar o topo
	if(m_sorted == false)
	{
		for(auto i = m_length/2; i > 0; i--)
		{
			fix_heap(i-1);
		}

		m_sorted = true;
	}

	return m_data[0]; 
}

template < typename ValueType, typename Compare >
template < typename InputIt >
PQ< ValueType, Compare >::PQ( InputIt first, InputIt last, const Compare & cmp ): m_cmp(cmp) 
{
    m_capacity = DEFAULT_SIZE;
    m_sorted = true;
    m_length = 0; 
    m_data = std::make_unique< ValueType [] >(m_capacity);

    for(auto it = first; it != last; it++)
    {  
        (*this).push(*it);
    }
}

template < typename ValueType, typename Compare >
PQ< ValueType, Compare >::PQ( const std::initializer_list< ValueType > & ilist , const Compare & cmp ):m_cmp(cmp)
{
    m_capacity = DEFAULT_SIZE;
    m_sorted = true;
    m_length = 0; 
    m_data = std::make_unique< ValueType [] >(m_capacity);

    for(const auto it: ilist)
    {  
        (*this).push(it);
    }
}

template < typename ValueType, typename Compare >
PQ< ValueType, Compare >::PQ( const PQ & other):m_cmp(other.m_cmp)
{
	*this = other;
}

template < typename ValueType, typename Compare >
PQ< ValueType, Compare > & PQ< ValueType, Compare >::operator=( const PQ< ValueType, Compare > & rhs )
{
	
	m_capacity = rhs.m_capacity;
    m_sorted = rhs.m_sorted;
    m_length = rhs.m_length; 
    m_data = std::make_unique< ValueType [] >(m_capacity);

    for(size_t i = 0; i < m_capacity; i++)
	{
	  m_data[i] = rhs.m_data[i];
	}


    return *this;

}


