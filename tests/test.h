#ifndef CPPCMS_SKEL_TESTS_H
#define CPPCMS_SKEL_TESTS_H 

#define CPPCMSSKEL_TEST(test)  \
    if (test) {\
        nothingFailed = false;\
        std::cout << "[fail]" << std::endl;\
    } else {\
        std::cout << "[ok]" << std::endl;\
    }


#endif
