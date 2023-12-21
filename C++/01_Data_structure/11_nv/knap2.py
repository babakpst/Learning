def knapsack_sequential(weights, values, capacity):
    n = len(weights)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            else:
                dp[i][w] = dp[i - 1][w]

    # Find the starting index of the consecutive selected items
    start_index = 0
    for j in range(capacity, 0, -1):
        if dp[n][j] > dp[n][j - 1]:
            start_index = j - 1
            break

    # Calculate the indices of the selected consecutive items
    selected_items = list(range(start_index, start_index + len(weights)))

    return dp[n][capacity], selected_items


# Example usage
#weights = [2, 2, 3, 5, 7]
#values = [1, 5, 8, 9, 10]
#capacity = 10

weights = [2, 4, 3, 2, 1]
values = [2, 4, 3, 2, 1]
capacity = 10


max_value, selected_items = knapsack_sequential(weights, values, capacity)

print("Maximum value:", max_value)
print("Selected items:", selected_items)

