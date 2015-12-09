#include <stdio.h>
#include <stdlib.h>

#include <check.h>

#include "check_suites.h"

struct suite {
    const char *name;
    Suite *(*get_suite)(void);
};

static struct suite suites[] =
{
    {"creation", creation_suite},
};

const int SUITE_COUNT = (sizeof(suites)/(sizeof(suites[0])));

int
main(int argc, char *argv[])
{
    SRunner *sr;
    int number_failed;
    int i;
    int j;

    sr = srunner_create(NULL);
    if (NULL != sr) {
        if (argc == 1) {
            for (i = 0; i < SUITE_COUNT; ++i) {
                srunner_add_suite(sr, suites[i].get_suite());
            }
        } else {
            for (i = 1; i < argc; ++i) {
                for (j = 0; j < SUITE_COUNT; ++j) {
                    if (0 == strcmp(argv[i], suites[i].name)) {
                        srunner_add_suite(sr, suites[j].get_suite());
                        break;
                    }
                }
            }
        }
    }

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (0 == number_failed);
}