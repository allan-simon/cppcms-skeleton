#ifndef CPPCMS_SKEL_TESTS_H
#define CPPCMS_SKEL_TESTS_H 



#define CPPCMSSKEL_TEST_RESULT_WORK(MESSAGE,FUNCTION_CALL,NO_FAILED)  \
    {\
        std::cout << MESSAGE;\
        bool success = FUNCTION_CALL;\
        if (!success) {\
            NO_FAILED = false;\
            std::cout << "[fail]" << std::endl;\
        } else {\
            std::cout << "[ok]" << std::endl;\
        }\
    }

#define CPPCMSSKEL_TEST_RESULT_NOT_WORK(MESSAGE,FUNCTION_CALL,NO_FAILED)  \
    {\
        std::cout << MESSAGE;\
        bool success = FUNCTION_CALL;\
        if (success) {\
            NO_FAILED = false;\
            std::cout << "[fail]" << std::endl;\
        } else {\
            std::cout << "[ok]" << std::endl;\
        }\
    }\





#define CPPCMSSKEL_TEST(test)  \
    if (test) {\
        nothingFailed = false;\
        std::cout << "[fail]" << std::endl;\
    } else {\
        std::cout << "[ok]" << std::endl;\
    }


#endif
