/*
 * Deon Naltchadjian
 * 0832759
 * Friday Oct 10, 2014
 * Lab Assignment 2
 */

package forecast;

/**
 *
 * @author Deon
 * The Temperature class contains a single variable, tempVal.
 * This stores the current temperature value of the Temperature object
 */

public class Temperature {
    
    private double tempVal;
    
    /**
     * Constructor 1: Blank
     * a temperature object with no parameters
     */
    
    public Temperature(){
        
    }
    
    /**
     * 
     * @param tempInput used to assign a value to tempVal during declaration
     */
    
    public Temperature(double tempInput){
        
        this.tempVal = tempInput;
        
    }

    /*
    method toCelsius
    params: current temp value, current unit of measure
    checks which unit the conversion begins from, and applies maths to find new value
    in converted unit
    assigns calling object's tempVal to new temperature
    */
    
    public void toCelsius(double currVal, char currentUnit){
        
        double newTemp;
        
        switch(currentUnit){
            case 'f':
                newTemp = (currVal - 32) * (5.0/9.0);
                break;
            case 'k':
                newTemp = currVal -273.15;
                break;
            default:
                newTemp = currVal;
        }
        
        this.tempVal = newTemp;
        
    }
    
    /*
    method toFarenheit
    params: current temp value, current unit of measure
    checks which unit the conversion begins from, and applies maths to find new value
    in converted unit
    assigns calling object's tempVal to new temperature
    */
    
    public void toFarenheit(double currVal, char currentUnit){
        
        double newTemp;
        
        switch(currentUnit){
            case 'c':
                newTemp = (9.0/5.0) * currVal + 32;
                break;
            case 'k':
                newTemp = (9.0/5.0) * (currVal -273.15) + 32;
                break;
            default:
                newTemp = currVal;
        }
        
        this.tempVal = newTemp;
        
    }
       
    /*
    method toKelvin
    params: current temp value, current unit of measure
    checks which unit the conversion begins from, and applies maths to find new value
    in converted unit
    assigns calling object's tempVal to new temperature
    */
    
    public void toKelvin(double currVal, char currentUnit){
        
        double newTemp;
        
        switch(currentUnit){
            case 'c':
                newTemp = currVal + 273.15;
                break;
            case 'f':
                newTemp = (currVal - 32) * (5.0/9.0) + 273.15;
                break;
            default:
                newTemp = currVal;
        }
        
        this.tempVal = newTemp;
        
    }
    
    /*
    setTemperature method
    param: new temperature value to be assigned
    mutator method to set calling object's tempVal to parameter tempVal
    */
    
    public void setTemperature(double tempVal){
        this.tempVal = tempVal;
    }
    
    /*
    getTemperature method
    accessor method to return calling object's tempVal
    */
    
    public double getTemperature(){
        return tempVal;
    }
    
    /*
    equals method
    used to check to see if the Temperature object temp value is the same as another
    returns boolean of equality or not
    */
    
    public boolean equals(Temperature other) {
        if (other == null) {
            return false;
        } else {
            return tempVal == other.tempVal;
        }
    }
    
    /*
    toString method
    returns a string containing "temperature: <calling object's temperature value> degrees" 
    */
    
    public String toString(){
        
        return "temperature: " + tempVal + " degrees ";
        
    }
}
