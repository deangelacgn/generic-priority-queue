#include "pq.h"


template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::fix_heap()
{

}

//OK
template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::move_down( size_type item_idx )
{
	// continua no loop enquanto o pai for maior do que um dos filhos
	while(m_cmp(m_data[item_idx], m_data[2 * item_idx + 1]) || m_cmp(m_data[item_idx], m_data[2 * item_idx + 2]))
	{
		//compara quem eh o filho maior ou menor entre os dois(esquerda e direita)
		// NAO TA VERIFICANDO OS CASOS EM QUE UM DOS FILHOS EH LIXO
	  if(m_cmp(m_data[2 * item_idx + 1], m_data[2 * item_idx + 2]))
	  {
	    auto aux = m_data[item_idx];
	    m_data[item_idx] = m_data[2 * item_idx + 2];
	    m_data[2 * item_idx + 2] = aux;

	    item_idx = 2 * item_idx + 2;
	  }
	  else
	  {
	    auto aux = m_data[item_idx];
	    m_data[item_idx] = m_data[2 * item_idx + 1];
	    m_data[2 * item_idx + 1] = aux;

	    item_idx = 2 * item_idx + 1;
	  }
	}
}

//OK
template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::move_up( size_type item_idx )
{
	// enquanto o pai for maior ou menor do que o filho
	while(m_cmp(m_data[item_idx/2 - 1], m_data[item_idx]))
	{
	  // swap entre o pai e o filho
	  auto aux = m_data[item_idx/2 - 1];
	  m_data[item_idx/2 - 1] = m_data[item_idx];
	  m_data[item_idx] = aux;

	  item_idx = item_idx/2 - 1;
	}
}

//OK
template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::reserve( size_type new_cap )
{
	//FALTA ATUALIZAR A NOVA CAPACIDADE
	if(new_cap >= m_capacity)
	{
	  return;
	}

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
	//verificar se o array suporta a insercao
	if(m_length >= m_capacity)
	{
		reserve(2 * m_capacity);
	}

	m_data[m_length] = x;

	m_length++;

	//VERIFICAR ESSA CONDICAO
	if(!m_cmp(m_data[m_length], m_data[m_length/2 - 1])) //ou for igual add essa funcionalidade
	{
		move_up(m_length);
	}
}

template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::toss( const ValueType & x )
{
	if(m_length >= m_capacity)
	{
		reserve(2 * m_capacity);
	}

	m_data[m_length] = x;

	m_length ++;

	//AJEITAR ESSAS CONDICOES
	if(!m_cmp(m_data[m_length], m_data[m_length/2 - 1]) && (m_sorted == true )) //ou for igual add essa funcionalidade
	{
		m_sorted = false;
	}
}

template < typename ValueType, typename Compare >
void PQ< ValueType, Compare >::pop()
{
	//REORDENAR A HEAP ANTES DE FAZER O POP

}

template < typename ValueType, typename Compare >
typename PQ< ValueType, Compare >::const_reference PQ< ValueType, Compare >::top( void ) 
{ 
	//REORDENAR A HEAP ANTES DE LIBERAR O TOPO 

	return m_data[0]; 
}


