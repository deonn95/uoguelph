package dayplanner;

/**
 * class represents a single other activity object.
 * @author Deon
 */
public class OtherActivity extends Activity{
    
    /**
     * creates a new other activity object and sets all attributes to null.
     */
    public OtherActivity(){
        
        super();
        
        setTitle(null);
        setStartTime(null);
        setEndTime(null);
        setComment(null);
        setLocation(null);
        
    }
    
    /**
     * creates a new other activity with the given attributes.
     * @param title the title of the activity.
     * @param sTime the starting time of the activity.
     * @param eTime the ending time of the activity.
     * @param comment a comment that best describes the activity.
     * @param location the location that the activity takes place in.
     */
    public OtherActivity(String title, Time sTime, Time eTime, String comment, String location){
        
        super(title, sTime, eTime, comment, location);
        
        setTitle(title);
        setStartTime(sTime);
        setEndTime(eTime);
        setComment(comment);
        setLocation(location);
    }
    
}
