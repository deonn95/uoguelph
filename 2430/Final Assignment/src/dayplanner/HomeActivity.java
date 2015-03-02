package dayplanner;

/**
 * Class represents a single home activity object.
 * @author Deon
 */
public class HomeActivity extends Activity{
    
    /**
     * creates an empty home activity and sets all variables to null
     */
    public HomeActivity(){
        
        super();
        
        setTitle(null);
        setStartTime(null);
        setEndTime(null);
        setComment(null);
    }
    
    
    /**
     * creates a new home activity with the given attributes.
     * @param title is the title of the activity
     * @param sTime is the starting time of the activity.
     * @param eTime is the ending time of the activity.
     * @param comment is a comment that best describes the activity.
     */
    public HomeActivity(String title, Time sTime, Time eTime, String comment){
        
        super(title, sTime, eTime, comment);
        
        setTitle(title);
        setStartTime(sTime);
        setEndTime(eTime);
        setComment(comment);
    }
}
