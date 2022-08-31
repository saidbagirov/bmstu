import ctypes



def initfib():
    pass

libfib = ctypes.CDLL("./libfib.so")
d_fill_fib = libfib.fill_fib
d_copy_unique = libfib.copy_unique
d_copy_unique.restype = ctypes.c_size_t

def fill_fib(count):
    arr = (ctypes.c_int * count)()
    d_fill_fib(arr, ctypes.c_size_t(count))
    return list(arr)

def copy_unique(l):
    src_len = len(l)
    src = (ctypes.c_int * src_len)(*l)
    count = d_copy_unique(src, ctypes.c_size_t(src_len), ctypes.c_void_p(0))
    arr = (ctypes.c_int * count)()
    d_copy_unique(src, ctypes.c_size_t(src_len), arr)
    return list(arr)

'''
def fill_fib(count):
    arr = []
    if count > 0:
        arr.append(0)
    if count > 1:
        arr.append(1)
    if count > 2:
        for _ in range(count - 2):
            arr.append(arr[-1] + arr[-2])
    return arr

def copy_unique(l):
    arr = []
    for v in l:
        if arr.count(v) == 0:
            arr.append(v)
    return arr
    '''