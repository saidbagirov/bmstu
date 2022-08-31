#include <stdio.h>
#include <math.h>
#include "../inc/matrix.h"
#include "../inc/error_codes.h"



int main()
{
    int result;
    matrix m1 = matrix_scan();
    if (!matrix_valid(&m1)) 
        result = READ_ERROR;
    else
    {
        matrix m2 = matrix_scan();
        if (!matrix_valid(&m2)) 
            result = READ_ERROR;
        else
        {
            int rho, gamma;
            if (scanf("%d %d", &rho, &gamma) != 2 || rho < 0 || gamma < 0)
                result = READ_ERROR;
            else
            {
                matrix_to_quad(&m1);
                matrix_to_quad(&m2);
                
                if ((result = matrix_fit(&m1, &m2)) == SUCCESS)
                {
                    matrix mp1 = matrix_power(&m1, rho);
                    if (!matrix_valid(&mp1))
                        result = MEMORY_ERROR;
                    else
                    {
                        matrix mp2 = matrix_power(&m2, gamma);
                        if (!matrix_valid(&mp2))
                            result = MEMORY_ERROR;
                        else
                        {
                            matrix m3 = matrix_multiply(&mp1, &mp2);
                            if (!matrix_valid(&m3))
                                result = MEMORY_ERROR;
                            else
                            {
                                matrix_print(&m3);

                                matrix_dispose(&m3);
                            }

                            matrix_dispose(&mp2);
                        }
                        matrix_dispose(&mp1);
                    }
                }
            }
            matrix_dispose(&m2);
        }
        matrix_dispose(&m1);
    }
    return result;
}