def solution(array, commands):
    answer = []
    for temp in commands:
        a = []
        i = temp[0]
        j = temp[1]
        k = temp[2]
        for h in range(i - 1, j):
            a.append(array[h])
        a.sort()
        result = a[k - 1]
        answer.append(result)     
    
    return answer
