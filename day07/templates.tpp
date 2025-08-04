#ifndef TEMPLATES_TPP
#define TEMPLATES_TPP

template <typename T>
void max(T x, T y)
{
	return (x > y ? x : y);
}
template <typename T>
void min(T x, T y)
{
	return (x < y ? x : y);
}

template <typename T>
void swap(T x, T y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
}

#endif TEMPLATES_TPP
