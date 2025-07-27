# 2. Stock Span Problem - Corrected
def calculate_stock_span(prices):
    stack = [] 
    spans = []
    for i in range(len(prices)):
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()
        if not stack:
            span = i + 1
        else:
            span = i - stack[-1]  
        spans.append(span)
        stack.append(i) 
    return spans

# Example Test
prices = [100, 80, 60, 70, 60, 75, 85]
expected_spans = [1, 1, 1, 2, 1, 4, 6]
calculated_spans = calculate_stock_span(prices)
print("Prices:           ", prices)
print("Expected Spans:   ", expected_spans)
print("Calculated Spans: ", calculated_spans)