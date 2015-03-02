package dayplanner;
/**
 * represents a time object that stores dates.
 * @author Deon
 */
public class Time {
    
    /**
     * stores the year of this time object.
     */
    int year;
    
    /**
     * stores the month of this time object.
     */
    int month;
    
    /**
     * stores the day of this time object.
     */
    int day;
    
    /**
     * stores the hour of this time object.
     */
    int hour;
    
    /**
     * stores the minute of this time object.
     */
    int minute;
    
    /**
     * creates a new empty time object.
     */
    public Time(){
        
    }
    
    /**
     * creates a new time object with the given attributes.
     * @param year the year of the object ie. (2014).
     * @param month the month of the object ie. (2).
     * @param day the day of the object ie. (15).
     * @param hour the hour of the object ie. (03).
     * @param minute the minute of the object ie. (56).
     */
    public Time(int year, int month, int day, int hour, int minute){
        this.year = year;
        this.month = month;
        this.day = day;
        this.hour = hour;
        this.minute = minute;
    }
    
    /**
     * accessor method, gives the year.
     * @return the year of the object.
     */
    public int getYear(){
        return year;
    }
    
    /**
     * accessor method, gives the month.
     * @return the month of the object.
     */
    public int getMonth(){
        return month;
    }
    
    /**
     * accessor method, gives the day.
     * @return the day of the object.
     */
    public int getDay(){
        return day;
    }
    
    /**
     * accessor method, gives the hour.
     * @return the hour of the object.
     */
    public int getHour(){
        return hour;
    }
    
    /**
     * accessor method, gives the minute.
     * @return the minute of the object.
     */
    public int getMinute(){
        return minute;
    }
    
    /**
     * mutator, change the year.
     * @param newYear the year to be set.
     */
    public void setYear(int newYear){
        this.year = newYear;
    }
    
    /**
     * mutator, changes the month.
     * @param newMonth the month to be set.
     */
    public void setMonth(int newMonth){
        this.month = newMonth;
    }
    
    /**
     * mutator, changes the day.
     * @param newDay the day to be set.
     */
    public void setDay(int newDay){
        this.day = newDay;
    }
    
    /**
     * mutator, changes the hour.
     * @param newHour the hour to be set.
     */
    public void setHour(int newHour){
        this.hour = newHour;
    }
    
    /**
     * mutator, changes the minute.
     * @param newMinute the minute to be set.
     */
    public void setMinute(int newMinute){
        this.minute = newMinute;
    }
    
    /**
     * Converts the time into a string to be printed easily.
     * @return the formatted string.
     */
    @Override
    public String toString(){
        String s = String.format("%02d:%02d, %02d/%02d/%d", hour, minute, day, month, year);
        return s;
    }
    
    /**
     * Compares two times to see if the first is less than, greater than, or equal to the second.
     * @param otherTime the second time in the comparison.
     * @return -1 if the first time (calendar-wise) comes after the second time.
     *         0 if the first time(calendar-wise) comes after the second time.
     *         1 if other is null
     */
    public int compareTime(Time otherTime){
        
        if(otherTime.isEmpty()){
            return 1;
        }
        
        if(year > otherTime.year){
            return -1;
        }
        else if(year == otherTime.year){
            if(month > otherTime.month){
                return -1;
            }
            else if(month == otherTime.month){
                if(day > otherTime.day){
                    return -1;
                }
                else if(day == otherTime.day){
                    if(hour > otherTime.hour){
                        return -1;
                    }
                    else if(hour == otherTime.hour){
                        if(minute > otherTime.minute){
                            return -1;
                        }
                    }
                }
            }
        }
        return 0;
    }
    
    /**
     * Checks if the time object is empty.
     * @return boolean true/ false.
     */
    public boolean isEmpty(){
        return this == null;
    }
    
}
