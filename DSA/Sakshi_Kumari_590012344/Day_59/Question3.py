def are_heaps_identical(heap1, heap2):
    if len(heap1) != len(heap2):
        return False
    for i in range(len(heap1)):
        if heap1[i] != heap2[i]:
            return False
    return True
