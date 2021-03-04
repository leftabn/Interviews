def sol(A, B):
  '''
   Find intersection between two arrays O(N);
  '''
  lenA = len(A)
  lenB = len(B)

  i = 0
  j = 0
  count = 0
  while i < lenA and j < lenB:
    if A[i] < B[j]:
      i += 1
    elif A[i] > B[j]:
      j += 1
    else:
      count += 1
      i += 1
      j += 1

  return count


print(sol([1,2,3,4], [3,4,5,6]))