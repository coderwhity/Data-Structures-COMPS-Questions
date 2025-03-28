str1 = "AXYT"
str2 = "AYZX"

dp = []
for i in range(len(str1)+1):
    dp.append([0 for i in range(len(str2)+1)])
print(dp)

for i in range(len(dp)-1):
    print("\n--------------------------")
    print(f"ROW {str1[i]}")
    x = i+1
    for j in range(len(dp[i])-1):
        y = j+1
        print(f"{str1[i]} {str2[j]}")
        print(f"{x} , {y}")
        # print(str1[i] == str2[j])
        if(str1[i] == str2[j]):
            print(f"SETTING VALUE OF dp[{x}][{y}] incrementing 1 in {dp[x][y]}")
            dp[x][y] = 1+ dp[x-1][y-1]
            print(dp[x][y])
        else:
            print(f"NOT EQUAL SO ACCESSING dp[{x}][{y-1}] and dp[{x-1}][{y}]")
            print(f"MAX SELECTED FROM : {dp[x][y-1]} and {dp[x-1][y]} is {max(dp[x][y-1],dp[x-1][y])}")
            dp[x][y] = max(dp[x-1][y], dp[x][y-1])
        print("--------------------------\n")
print(dp)
