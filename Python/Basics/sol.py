def findGroupID(listPFR):
    n = len(listPFR)
    score = [0] * n
    stack = []

    for i in range(n):
        while stack and listPFR[i] > listPFR[stack[-1]]:
            top = stack.pop()
            if stack and listPFR[stack[-1]] > listPFR[top]:
                score[top] = 5
            else:
                score[top] = 10

        if stack and listPFR[stack[-1]] > listPFR[i]:
            score[i] = 5
        else:
            score[i] = 15

        stack.append(i)

    while stack:
        top = stack.pop()
        if stack and listPFR[stack[-1]] > listPFR[top]:
            score[top] = 5
        else:
            score[top] = 10

    return sum(score)