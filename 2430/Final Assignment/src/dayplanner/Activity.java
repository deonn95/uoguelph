package dayplanner;

/**
 * Represents a single generic activity object. This is used for manipulation of activities.
 * The attributes of home, school and other activities are transferred into a generic activity so generic operations can be performed.
 * Once completed, the original activity type is restored by receiving the newly altered attributes.
 * @author Deon
 */
public class Activity {
    
    /**
     * stores the title of the activity.
     */
    private String title;
    
    /**
     * stores the starting time of the activity in a Time object.
     */
    private Time sTime;
    
    /**
     * stores the ending time of the activity in a Time object.
     */
    private Time eTime;
    
    /**
     * stores a comment that best describes the activity.
     */
    private String comment;
    
    /**
     * stores the location that the activity takes place in.
     */
    private String location;
    
    /**
     * Creates an empty generic activity, sets all attributes to null.
     */
    public Activity(){
        
        title = null;
        sTime = null;
        eTime = null;
        comment = null;
        location = null;
    }
    
    /**
     * creates a new generic activity with the given attributes.
     * @param title the title of the activity.
     * @param sTime the starting time of the activity.
     * @param eTime the ending time of the activity.
     * @param comment a comment that best describes the activity.
     */
    public Activity(String title, Time sTime, Time eTime, String comment){
        this.title = title;
        this.sTime = sTime;
        this.eTime = eTime;
        this.comment = comment;
    }
    
    /**
     * creates a new generic activity with the given attributes.
     * @param title the title of the activity.
     * @param sTime the starting time of the activity.
     * @param eTime the ending time of the activity.
     * @param comment a comment that best describes the activity.
     * @param location the location that the activity takes place in.
     */
    public Activity(String title, Time sTime, Time eTime, String comment, String location){
        this.title = title;
        this.sTime = sTime;
        this.eTime = eTime;
        this.comment = comment;
        this.location = location;
    }
    
    /**
     * accessor of the title.
     * @return the title of the activity.
     */
    public String getTitle(){
        return title;
    }
    
    /**
     * accessor of the start time.
     * @return the starting time of the activity.
     */
    public Time getStartTime(){
        return sTime;
    }
    
    /**
     * accessor of end time.
     * @return the ending time of the activity.
     */
    public Time getEndTime(){
        return eTime;
    }
    
    /**
     * accessor of the comment.
     * @return the comment of the activity. 
     */
    public String getComment(){
        return comment;
    }
    
    /**
     * gets the location of the activity.
     * @return string of the location.
     */
    public String getLocation(){
        return location;
    }
    
    /**
     * mutator, changes the title of the activity.
     * @param newTitle the new title to be set.
     */
    public void setTitle(String newTitle){
        this.title = newTitle;
    }
    
    /**
     * mutator, changes the start time of an activity.
     * @param newStartTime the new start time.
     */
    public void setStartTime(Time newStartTime){
        this.sTime = newStartTime;
    }
    
    /**
     * mutator, changes the end time of an activity.
     * @param newEndTime the new ending time.
     */
    public void setEndTime(Time newEndTime){
        this.eTime = newEndTime;
    }
    
    /**
     * mutator, changes the comment of an activity.
     * @param newComment the new comment.
     */
    public void setComment(String newComment){
        this.comment = newComment;
    }
    
    /**
     * changes the location of the activity.
     * @param newLocation the location to be set.
     */
    public void setLocation(String newLocation){
        this.location = newLocation;
    }
    
    /**
     * Converts the activity object to a string so it can be printed easily.
     * If location is set to null, it does not need to be in the string so return the second string.
     * @return the formatted string.
     */
    @Override
    public String toString(){
        if(location != null){
            return title + ": Starts at " + sTime.toString() + ", ends at " + eTime.toString() + ", Comment: " + comment + ", Location: " + location;
        } 
        else{
            return title + ": Starts at " + sTime.toString() + ", ends at " + eTime.toString() + ", Comment: " + comment;
        }
    }
    
    
    /**
     * checks to see if the activity object is null.
     * @return boolean indication of null or not.
     */
    public boolean isNull(){
        return title == null;
    }
}
