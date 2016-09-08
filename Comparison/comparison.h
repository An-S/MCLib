#ifndef COMPARISON_H_INCLUDED
#define COMPARISON_H_INCLUDED

#ifdef MAKEFORWARDDEKL
#undef MAKEFORWARDDEKL
#endif

//#define MAKEFORWARDDEKL(type) bool MCLib_lessThan_##type(const void *a, const void *b);

bool MCLib_lessThan_Int(const void *a, const void *b);
bool MCLib_lessThan_Str(const void *a, const void *b);
bool MCLib_lessThanOrEq_Int(const void *a, const void *b);
bool MCLib_lessThanOrEq_Str(const void *a, const void *b);

bool MCLib_lessThan_Char(const void *a, const void *b);
//MAKEFORWARDDEKL(OrEq_Str);
//MAKEFORWARDDEKL(OrEq_Int);

#undef MAKEFORWARDDEKL

#endif // COMPARISON_H_INCLUDED
