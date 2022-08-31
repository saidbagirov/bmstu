#include "../inc/matrix.h"
#include "../inc/error_codes.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>



matrix matrix_create(size_t w, size_t h)
{
    matrix m;
    m.w = 0;
    m.h = 0;
    m.data = NULL;
    if (w > 0 && h > 0)
    {
        m.w = w;
        m.h = h;
        m.data = malloc(w * h * sizeof(int64_t));
        if (m.data == NULL) 
            m.w = m.h = 0;
    }
    return m;
}

void matrix_dispose(matrix *m)
{
    free(m->data);
}

matrix matrix_invalid()
{
    matrix m;
    m.w = 0;
    m.h = 0;
    m.data = NULL;
    return m;
}

matrix matrix_scan()
{
    matrix m;
    int w, h;
    if (scanf("%d %d", &h, &w) != 2 || h < 1 || w < 1) 
        m = matrix_invalid();
    else
    {
        m = matrix_create(w, h);
        if (!matrix_valid(&m)) 
            m = matrix_invalid();
        else
        {
            for (size_t i = 0; i < w * h; i++)
            {
                if (scanf("%"SCNi64, m.data + i) != 1)
                {
                    matrix_dispose(&m);
                    m = matrix_invalid();
                    break;
                }
            }
        }
    }

    return m;
}

void matrix_print(const matrix *m)
{
    for (size_t y = 0; y < m->h; y++)
    {
        for (size_t x = 0; x < m->w; x++)
        {
            printf("%-3"SCNi64" ", m->data[m->w * y + x]);
        }
        printf("\n");
    }
}

int64_t matrix_valid(const matrix *m)
{
    return m->data != NULL;
}

int64_t matrix_get_elem(const matrix *m, size_t x, size_t y)
{
    return m->data[y * m->w + x];
}

void matrix_set_elem(matrix *m, size_t x, size_t y, int64_t v)
{
    m->data[y * m->w + x] = v;
}

void matrix_set_identy(matrix *m)
{
    for (size_t y = 0; y < m->h; y++)
    {
        for (size_t x = 0; x < m->w; x++)
        {
            if (y != x) 
                m->data[y * m->w + x] = 0;
            else 
                m->data[y * m->w + x] = 1;
        }     
    }
}

matrix matrix_multiply(const matrix *l, matrix const *r)
{
    matrix m = matrix_create(r->w, l->h);
    if (matrix_valid(&m)) 
    {
        for (size_t y = 0; y < l->h; y++)
        {
            for (size_t x = 0; x < r->w; x++)
            {
                m.data[y * m.w + x] = 0;
                for (size_t z = 0; z < l->w; z++)
                {
                    m.data[y * m.w + x] += l->data[y * l->w + z] * r->data[z * r->w + x];
                }
            }     
        }
    }
    return m;
}

matrix matrix_power(const matrix *m, int64_t p)
{
    matrix res = matrix_create(m->w, m->h);
    if (matrix_valid(&res)) 
    {
        matrix_set_identy(&res);

        for (int64_t i = 0; i < p; i++)
        {
            matrix t = matrix_multiply(&res, m);
            matrix_dispose(&res);
            res = t;
            if (!matrix_valid(&t)) 
                break;
        }
    }
    return res;
}

void matrix_set(matrix *m, const int64_t data[])
{
    memcpy(m->data, data, m->w * m->h * sizeof(int64_t));
}

int matrix_equeals(const matrix *l, const matrix *r)
{
    int res = 0;
    if (l->w != r->w || l->h != r->h)
        res = 0;
    else if (l->data == NULL && r->data == NULL)
        res = 1;
    else if (l->data == NULL || r->data == NULL) 
        res = 0;
    else 
    {
        res = 1;
        for (size_t i = 0; i < l->w * l->h; i++)
        {
            if (l->data[i] != r->data[i])
            {
                res = 0;
                break;
            }
        }
    }

    return res;
}

void matrix_remove_row(matrix *m, size_t r)
{
    for (size_t y = r; y < m->h - 1; y++)
        for (size_t x = 0; x < m->w; x++)
            m->data[y * m->w + x] = m->data[(y + 1) * m->w + x];
    m->h--;
}

void matrix_remove_col(matrix *m, size_t c)
{
    for (size_t y = 0; y < m->h; y++)
    {
        size_t nx = 0;
        for (size_t x = 0; x < m->w; x++)
        {
            if (x != c)
                m->data[y * (m->w - 1) + nx++] = m->data[y * m->w + x];
        }
    }
    m->w--;
}

int matrix_max(const matrix *m)
{
    int64_t max = m->data[0];
    int ind = 0;
    for (size_t i = 1; i < m->w * m->h; i++)
    {
        if (m->data[i] >= max)
        {
            max = m->data[i];
            ind = i;
        }
    }
    return ind;
}

void matrix_to_quad(matrix *m)
{
    while (m->w > m->h)
    {
        int64_t col = matrix_max(m) % m->w;
        matrix_remove_col(m, col);
    }
    while (m->w < m->h)
    {
        int64_t row = matrix_max(m) / m->w;
        matrix_remove_row(m, row);
    }
}

void matrix_enlarge(matrix *m, size_t s)
{
    matrix n = matrix_create(s, s);
    if (!matrix_valid(&n))
    {
        matrix_dispose(m);
        *m = matrix_invalid();
    }

    for (size_t x = 0; x < m->w; x++)
        for (size_t y = 0; y < m->h; y++)
            matrix_set_elem(&n, x, y, matrix_get_elem(m, x, y));

    for (size_t x = 0; x < m->w; x++)
    {
        int64_t sum = 0;
        for (size_t y = 0; y < m->h; y++)
            sum += matrix_get_elem(m, x, y);

        for (size_t dy = 0; dy < s - m->h; dy++)
        {
            int64_t val = (int64_t)floor((double)sum / (double)(m->h + dy));
            matrix_set_elem(&n, x, m->h + dy, val);
            sum += val;
        }
    }

    for (size_t y = 0; y < s; y++)
    {
        int64_t max = matrix_get_elem(&n, 0, y);
        for (size_t x = 1; x < m->h; x++)
        {
            int64_t val = matrix_get_elem(&n, x, y);
            if (val < max) 
                max = val;
        }    

        for (size_t dx = 0; dx < s - m->h; dx++)
            matrix_set_elem(&n, m->w + dx, y, max);
    }

    matrix_dispose(m);
    *m = n;
}

int matrix_fit(matrix *m1, matrix *m2)
{
    int res = SUCCESS;
    if (m1->w > m2->w) 
    {
        matrix_enlarge(m2, m1->w);
        if (!matrix_valid(m2))
        {
            matrix_dispose(m1);
            res = MEMORY_ERROR;
        } 
    }
    else if (m2->w > m1->w) 
    {
        matrix_enlarge(m1, m2->w);
        if (!matrix_valid(m1))
        {
            matrix_dispose(m2);
            res = MEMORY_ERROR;
        } 
    }
    return res;
}