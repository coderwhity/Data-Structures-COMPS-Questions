def func(arr):
    print(f"ARRAY : {arr}")
    if len(arr) == 1:
        return [arr[0], arr[0]]
    elif len(arr) == 2:
        return [min(arr), max(arr)]
    else:
        x = len(arr) // 2
        m = func(arr[:x])
        n = func(arr[x:])
        print(f"LEN OF M : {len(m)}")
        print(f"LEN OF N : {len(n)}")

        minm = min(m[0], n[0])
        maxm = max(m[1], n[1])

        return [minm, maxm]

op = func([33, 11, 44, 55, 66, 22])
print(f"Final Min and Max: {op}")
