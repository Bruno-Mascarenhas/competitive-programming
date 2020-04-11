import os

for filename in os.listdir():
    src = filename
    dst = filename[:21]
    os.rename(src,dst)