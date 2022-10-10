#Simple api weather app to tell the user the weather of the city of their choice.

import requests

apiKey = 'dac348b14e06e4f6ca91651f5a1235ef'

userInput = input("Enter city of choice: ")

weatherData = requests.get(f"https://api.openweathermap.org/data/2.5/weather?q={userInput}&appid={apiKey}")


if weatherData.json()['cod'] == '404':
    print("Please try again")

   
else :

    tempvalue = weatherData.json()['main']['temp']
    
    def kelvintofarenhiet(temp):
        fahrenheit = 1.8 * (temp - 273) + 32
        return fahrenheit

    fahrenhiet = kelvintofarenhiet(tempvalue)
    
    weather = weatherData.json()['weather'][0]['main']
    
    print("The weather in " + userInput + " is " + weather )
    print("The tempature is ") 
    print(fahrenhiet)







