
# Babak Poursartip  
# 28 Oct 2019

# Lambda Function

# Conversts Celsius to Fahrenheit
def CelsiusToFahrenheit(temp):
    return (temp * 9/5) + 32

# Converts Fahrenheit to Celsisus
def FahrenheitToCelsius(temp):
    return (temp-32) * 5/9

def main():
  """ main()=> lambda function
  """
  C_temps = [10, 15, 18, 25]  
  F_temps = [30, 32, 50, 60, 100]

  # convert C to F
  print(list(map(FahrenheitToCelsius, F_temps))) # this is great
  print(list(map(CelsiusToFahrenheit, C_temps)))

  # lambda
  print(list(map(lambda t:(t-32) * 5/9, F_temps))) # this is great
  print(list(map(lambda t:(t * 9/5) + 32, C_temps)))


if __name__== "__main__":
  main()