def knapsack_sequential(weights, values, capacity):
    n = len(weights)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            else:
                dp[i][w] = dp[i - 1][w]

    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            print(f"{dp[i][w]} ", end="")
        print()



    # Find the selected items
    selected_items = []
    i, j = n, capacity
    while i > 0 and j > 0:
        if dp[i][j] != dp[i - 1][j]:
            selected_items.append(i - 1)
            j -= weights[i - 1]
        i -= 1

    selected_items.reverse()

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
