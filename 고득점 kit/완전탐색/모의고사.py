arr1 = [1,2,3,4,5]
arr2 = [2,1,2,3,2,4,2,5]
arr3 = [3,3,1,1,2,2,4,4,5,5]

def solution(answers):
    answer = []
    result = [0,0,0]
    for i in range(len(answers)):
        if (answers[i] == arr1[i % len(arr1)]):
            result[0] += 1
        if (answers[i] == arr2[i % len(arr2)]):
            result[1] += 1
        if (answers[i] == arr3[i % len(arr3)]):
            result[2] += 1
    
    m = max(result)
    for i in range(3):
        if (m == result[i]):
            answer.append(i + 1)
    
    return answer
