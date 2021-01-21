def solution(participant, completion):
    for name in participant:
        if (not name in completion) or participant.count(name) != completion.count(name):
            answer = name
            break
    return answer