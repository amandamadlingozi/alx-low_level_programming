from ctypes import *

so_file = "100-operations.so"

my_function = CDLL(so_file)

print("Done!")
