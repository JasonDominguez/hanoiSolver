#include "hanoi.h"

Hanoi::Hanoi(unsigned int n) : m_Disks(n)
{ 
	// sets then initial state for the problem
	for (int i=n; i>0; --i) m_Pegs[0].push(i);
}

void Hanoi::MakeMove(std::ostream& os, unsigned int peg1, unsigned int peg2)
{
	// moves the disks between pegs appropriately
	// calls PrintMove for each disk movement
	if (m_Pegs[peg1].empty()) {
		std::swap(peg1, peg2);
	}
	else if (!m_Pegs[peg2].empty() && m_Pegs[peg1].top() > m_Pegs[peg2].top()) {
		std::swap(peg1, peg2);
	}
	PrintMove(os, m_Pegs[peg1].top(), peg1, peg2);
	m_Pegs[peg2].push(m_Pegs[peg1].top());
	m_Pegs[peg1].pop();
}