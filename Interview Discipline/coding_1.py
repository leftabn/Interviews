def sol(inputList, maximumNumbers):
  '''
   Given an integer array A of size N.
   You can pick B elements from either left or right end of the array A to get maximum sum.
   Find and return this maximum possible sum.
  '''

  if (maximumNumbers == 1):
    return max(inputList)

  sumFront = 0
  sumBack = 0
  sumFrontAux = 0
  sumBackAux = 0
  tmp = maximumNumbers

  for i in range(0, maximumNumbers):
    sumFrontAux += inputList[i]
    if (sumFront > sumFrontAux):
      break
    if (inputList[i] > sumFrontAux):
      sumFrontAux = inputList[i]
    if ((sumFrontAux < sumFront and sumFront == 0) or (sumFrontAux > 0 and sumFrontAux > sumFront)):
      sumFront = sumFrontAux
      tmp -= 1
      if (tmp == 0):
        break

  maxStep = maximumNumbers-tmp-1
  for i in range(len(inputList)-1, maxStep, -1):
    sumBackAux += inputList[i]
    if (sumBack > sumBackAux):
      break
    if (inputList[i] > sumBackAux):
      sumBackAux = inputList[i]
    if ((sumBackAux < sumBack and sumBack == 0) or (sumBackAux > 0 and sumBackAux > sumBack)):
      sumBack = sumBackAux
      tmp -= 1
      if (tmp == 0):
        break

  if ((sumFront+sumBack > sumFront) and (sumFront+sumBack > sumBack)):
    return (sumFront+sumBack)
  elif (sumBack > (sumFront+sumBack) and (sumBack > sumFront)):
    return sumBack

  return sumFront


print(sol([5, -2, 3, 1, 2], 3))
