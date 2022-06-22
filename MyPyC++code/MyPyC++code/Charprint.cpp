#include "Charprint.h"
#include <iostream>
#include <string>
using namespace std;

void Charprint::PRINTCHAR(size_t n, char c) {
	m_result = " ";
	for (m_i = n; m_i > 0; m_i--) {
		m_result = m_result + c;
	}
	cout << m_result;
}