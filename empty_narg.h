
// IS_EMPTY() returns nothing if the parameter list is empty and a single ',' (comma) otherwise.
// The parameter list can have up to 32 parameters
#define IS_EMPTY(...) IS_EMPTY1(__VA_ARGS__)
#define IS_EMPTY1(...) IS_EMPTY2(DROP_PARAMS  __VA_ARGS__ (,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,EMPTY))
#define IS_EMPTY2(...) IS_EMPTY3(__VA_ARGS__)
#define IS_EMPTY3(f,...) TEST_EMPTY_##f )
#define DROP(...)
#define DROP_PARAMS(...) DROP_PARAMS1(__VA_ARGS__,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,)
#define DROP_PARAMS1(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,__m,...) CATCH_##__m
#define TEST_EMPTY_DROP_PARAMS , DROP(
#define TEST_EMPTY_CATCH_EMPTY DROP(
#define TEST_EMPTY_CATCH_ , DROP(


#define TEST_EMPTY(...) __VA_ARGS__ : TAKE_2ND(IS_EMPTY(__VA_ARGS__) not,) empty
#define TAKE_2ND(...) TAKE_2ND_(__VA_ARGS__,,)
#define TAKE_2ND_(f,s,...) s

TEST_EMPTY()
TEST_EMPTY(a.b.)
TEST_EMPTY(A)
TEST_EMPTY(())
TEST_EMPTY(int()(more))
TEST_EMPTY((int))
TEST_EMPTY(foo bar)
TEST_EMPTY(*)
  
#define FOO(x) x
#define BAR
TEST_EMPTY(FOO(BAR))
TEST_EMPTY(1,2)
TEST_EMPTY(1.)
TEST_EMPTY(.1)
TEST_EMPTY(1,)
TEST_EMPTY((int)(float))
TEST_EMPTY(() this)
TEST_EMPTY(() is, () not ()  empty ())
TEST_EMPTY(,notempty)
TEST_EMPTY((),notempty)
TEST_EMPTY((1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,))


// NARGS() counts the number of arguments and returns it as an decimal literal
#define NARGS(...) NARGS1(__VA_ARGS__ IS_EMPTY(__VA_ARGS__) 33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0)
#define NARGS1(...) NARGS2(__VA_ARGS__)
#define NARGS2(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,_21,_22,_23,_24,_25,_26,_27,_28,_29,_30,_31,_32,_n,...) _n

NARGS()
NARGS(1)
NARGS(1,2,3)
NARGS(,)
NARGS((int)(),*)
NARGS(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32)



