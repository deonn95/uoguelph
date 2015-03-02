/*
 * Deon Naltchadjian
 * 0832759
 * Friday Oct 10, 2014
 * Lab Assignment 2
 */

package forecast;
import java.util.Scanner;
import java.util.Random;
import java.util.ArrayList;

/**
 * @author Deon
 * The Forecast class contains the main method, the command loop and handles choices
 * Contains a temperature ArrayList, uses scanner components to determine events.
 * DAYS is a constant used to determine how many days are in the forecast
 *  For our purposes, set to 7, but can be changed at any time.
 */

public class Forecast {
    
    public static final int DAYS = 7;    
    
    /*
    main method
    Uses scanner to store temperature inputs, if anything other than a number is inputted, generates random temperature from 0-40 degrees
    Stores the temperatures in an arraylist
    Holds command loop to choose between the 5 options:
        1 - 4 run individual methods desribed below
        5 exits
        all other input rejected and asked for proper input
    */
    
    public static void main(String[] args) {
        // TODO code application logic here
        
        ArrayList<Temperature> list = new ArrayList<>();
        Scanner s = new Scanner(System.in);
        Random rand = new Random();
        
        char currentUnit = 'c';
        double temp;
        String choice, input;
        
        System.out.println("Enter temperatures (in degrees Celsius), or enter anything else to generate random temperatures.");
        
        for(int i = 0; i < DAYS; i++){
            
            input = s.nextLine();
            
                try{
                    temp = Double.parseDouble(input);
                    list.add(i, new Temperature(temp));

                }catch(Exception e){
                    list.add(i, new Temperature());
                    temp = rand.nextDouble() * (35);
                    list.get(i).setTemperature(temp);
                }
            
            System.out.println("Day " + (i + 1) + " " + list.get(i).toString() + "Celsius");
            
        }
            
        do{
            
            System.out.println("1. Print 7-Day Forecast");
            System.out.println("2. Convert Temperature Format");
            System.out.println("3. Change Forecast for Specific Day");
            System.out.println("4. Same Weather");
            System.out.println("5. Exit");
            
            choice = s.nextLine();
            
            switch(choice){
                case "1":
                    printForecast(list, currentUnit);
                    break;
                case "2":
                    currentUnit = convert(list, currentUnit);
                    break;
                case "3":
                    changeDay(list);
                    break;
                case "4":
                    sameWeather(list, currentUnit);
                    break;
                case "5":
                    break;
                default:
                    System.out.println("Please enter a valid choice.");
            }
            
        }
        while(!choice.equals("5"));
    }
    
    /*
    printForecast method
    params: ArrayList of temperatures, char of the current unit of measure
    determines the unit of measurement, creates a string with the correct unit of measure
    runs loop to print all temperatures in a formatted string
    return to main
    */
    
    public static void printForecast(ArrayList<Temperature> temperatures, char currentUnit){
        
        String unitStr = "";
        
        switch(currentUnit){
            case 'c':
                unitStr = "Celsius";
                break;
            case 'f':
                unitStr = "Farenheit";
                break;
            case 'k':
                unitStr = "Kelvin";
        }
        
        for(int i = 0; i < temperatures.size(); i++){
            System.out.println("Day " + (i+1) + " " + temperatures.get(i).toString() + unitStr);   
        }
        
        System.out.println();
        
    }
    
    /*
    convert method
    params: Temperature ArrayList, char of the current unit of measure
    has a loop which asks user to input their new unit of choice
    scanner scans for "celsius", "farenheit" or "kelvin"
    uses Temperature class methods to convert
    returns the new unit of measure char to main
    */
    
    public static char convert(ArrayList<Temperature> temperatures, char currentUnit){
        
        Scanner s = new Scanner(System.in);
        String toUnit;
        char newUnit = 'u';
        boolean loop = true;
        
        System.out.println("Please enter the unit you would like to convert to: (Celsius, Farenheit, Kelvin)");
        
        do{
            toUnit = s.next();
        
            if(toUnit.equalsIgnoreCase("celsius")){
                for(int i = 0; i < DAYS; i++){
                    temperatures.get(i).toCelsius(temperatures.get(i).getTemperature(), currentUnit);
                }
                loop = false;
                newUnit = 'c';
            }
            else if(toUnit.equalsIgnoreCase("farenheit")){
                for(int i = 0; i < DAYS; i++){
                    temperatures.get(i).toFarenheit(temperatures.get(i).getTemperature(), currentUnit);
                }
                newUnit = 'f';
                loop = false;
            }
            else if(toUnit.equalsIgnoreCase("kelvin")){
                for(int i = 0; i < DAYS; i++){
                    temperatures.get(i).toKelvin(temperatures.get(i).getTemperature(), currentUnit);
                }
                newUnit = 'k';
                loop = false;
            }
            else{
                System.out.println("Please enter a correct unit");
            }
        }while(loop);
        
        return newUnit;
        
    }
    
    /*
    changeDay method
    params: Temperature Arraylist
    loops to get the user input of which day they would like to change (1-7)
    once gathered, begins new loop that asks for temperature values on selected day
    sets the new temperature to the desired list object
    */
    
    public static void changeDay(ArrayList<Temperature> temperatures){
        
        Scanner s = new Scanner(System.in);
        int choice = 0;
        double newTemp = 0;
        String userStr;
        boolean loop = true;
        
        System.out.println("Please enter the day you would like to change (1-7):");
        
        do{
            userStr = s.nextLine();
            try{
                choice = Integer.parseInt(userStr);
                if(choice >= 1 && choice <= 7){
                    loop = false;
                }
                else{
                    System.out.println("Only numbers 1-7 are accpeted.");
                }
            }catch(Exception e){
                System.out.println("Please enter an integer from 1 to 7.");
            }
        }while(loop);
        
        loop = true;
        System.out.println("Enter a temperature for that day:");
        
        do{
            userStr = s.nextLine();
            try{
                newTemp = Double.parseDouble(userStr);
                loop = false;
            }catch(Exception e){
                System.out.println("Please enter a floating point number.");
            }
        }while(loop);
        
        temperatures.get(choice - 1).setTemperature(newTemp);
        
    }
    
    /*
    sameWeather method
    creates a string that stores the selected unit word
    uses two loops to parse through the list, returning matches and incrementing match counter
    prints the number of matches found, as well as each match.
    */
    
    public static void sameWeather(ArrayList<Temperature> temperatures, char currentUnit){
        
        int matches = 0;
        String unitStr = "";
        
        switch(currentUnit){
            case 'c':
                unitStr = "Celsius";
                break;
            case 'f':
                unitStr = "Farenheit";
                break;
            case 'k':
                unitStr = "Kelvin";
        }
        
        for(int i = 0; i < DAYS; i++){
            for(int j = 0; j < DAYS; j++){
                if(temperatures.get(i).equals(temperatures.get(j)) && i < j){
                    System.out.println("The temperatures of days " + (i+1) + " and " + (j+1) + " are the same, " + temperatures.get(i).toString() + unitStr);
                    matches++;
                }
            }
        }
        
        if(matches == 0){
            System.out.println("No matches were found between days.");
        }
        else{
            System.out.println(matches + " match(es) were found between days.");
        }
        
    }
    
}


