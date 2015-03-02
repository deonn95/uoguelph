package dayplanner;

/**
 * class represents a single school activity object.
 * @author Deon
 */
public class SchoolActivity extends Activity{
    
    
    /**
     * creates a new school activity, sets all variables to null.
     */
    public SchoolActivity(){
        
        super();
        
        setTitle(null);
        setStartTime(null);
        setEndTime(null);
        setComment(null);
        
    }
    
    /**
     * creates a new school activity with the given parameters.
     * @param title the activity title.
     * @param sTime the starting time of the activity.
     * @param eTime the ending time of the activity.
     * @param comment the activity comment.
     */
    public SchoolActivity(String title, Time sTime, Time eTime, String comment){
        
        super(title, sTime, eTime, comment);
        
        setTitle(title);
        setStartTime(sTime);
        setEndTime(eTime);
        setComment(comment);
    }
}
