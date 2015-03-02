package dayplanner;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 * DayPlanner class represents the Day Planner main program
 * includes main method, carries major functions.
 * @author Deon Naltchadjian
 */
public class DayPlanner {

    /**
     * Used to store max amount of activities per array
     */
    public static final int MAX_ACTIVITIES = 20;
    
    /**
     * Creates window
     */
    public static GUI gui;
    
    /**
     * @param args for command line arguments. First 
     */  
    public static void main(String[] args) throws IOException {
        
        /**
         * Scanner object. This will handle all user input in the main method.
         */
        Scanner s = new Scanner(System.in);
        gui = new GUI();
        
        /**
         * loop that initializes all elements of the array to null.
         * Used to avoid null pointer exceptions.
         */
        
        gui.txtMessage.append("You opened with " + args.length + " command arguments.\n");
        
        
        if(args.length == 2){
            gui.outfile = args[1];
            gui.list = createList(args[0]);
            for(int i = 0; i < gui.list.size(); i++){
                if(gui.list.get(i).getClass() == HomeActivity.class){
                    gui.hCount++;
                }
                else if(gui.list.get(i).getClass() == SchoolActivity.class){
                    gui.sCount++;
                }
                else{
                    gui.oCount++;
                }
            }
        }
        else{
            gui.list = new ArrayList<>(MAX_ACTIVITIES * 3);
        }
        
        
        
    }
    
    /**
     * Creates a new home activity.
     * Creates a generic activity, copies its contents and returns the new home object.
     * @return the home activity created.
     */
    public static HomeActivity createHome(){
        
        HomeActivity newHome;
        Activity newActivity = createActivity();
        
        newHome = new HomeActivity(newActivity.getTitle(), newActivity.getStartTime(), newActivity.getEndTime(), newActivity.getComment());
        
        return newHome;
        
    }
    
    
    /**
     * Creates a new school activity.
     * Creates a generic activity, copies its contents and returns the new school object.
     * @return the school activity created.
     */
    public static SchoolActivity createSchool(){
        
        SchoolActivity newSchool;
        Activity newActivity = createActivity();
        
        newSchool = new SchoolActivity(newActivity.getTitle(), newActivity.getStartTime(), newActivity.getEndTime(), newActivity.getComment());
        
        return newSchool;
        
    }
    
    
    /**
     * Creates a new other activity.
     * Creates a generic activity, copies its contents and returns the new other object.
     * @return the other activity created.
     */
    public static OtherActivity createOther(){
        
        OtherActivity newOther;
        Activity newActivity = createActivity();
        
        newOther = new OtherActivity(newActivity.getTitle(), newActivity.getStartTime(), newActivity.getEndTime(), newActivity.getComment(), newActivity.getLocation());
        
        return newOther;
        
    }
    
    /**
     * Takes in an activity type via string, creates a generic activity.
     * Using a series of user input commands, takes in the required values to make a new activity.
     * @return the newly created generic activity
     */
    public static Activity createActivity(){
        
        /**
         * Creates a new empty generic activity.
         * fills it with info taken from gui.
         */
        Activity newActivity = new Activity();
        newActivity.setTitle(gui.title);
        newActivity.setStartTime(gui.st);
        newActivity.setEndTime(gui.et);
        newActivity.setComment(gui.comment);
        newActivity.setLocation(gui.location);
        return newActivity;
        
    }
    
    /**
     * Searches through an array of generic activities.
     * Passes in an activity array  list to be searched.
     * Asks the user to enter a start and end time, then keywords.
     * Parses through array and finds matches
     * @param list the list to be searched
     */
    public static void searchActivity(ArrayList<Activity> toSearch){
        
        boolean matches[] = new boolean[toSearch.size()];
        String[] keywords = gui.title.split(" ");
        
        if(gui.st == null){
            gui.st = new Time(0, 0, 0, 0, 0);
        }
        if(gui.et == null){
            gui.et = new Time(Integer.MAX_VALUE, 12, 31, 23, 59);
        }
        
        if(!gui.title.equals("")){
            for(int i = 0; i < toSearch.size(); i++){
                if(!toSearch.get(i).isNull()){
                    /**
                    * Loop that parses through keywords.
                    * If the keywords are there, set the boolean match at that index to true.
                    */
                    for(int j = 0; j < keywords.length; j++){
                        if(toSearch.get(i).getTitle().contains(keywords[j])){
                            matches[i] = true;
                        }
                        else{
                            matches[i] = false;
                            j = keywords.length;
                        }
                    }
                    if(gui.st.compareTime(toSearch.get(i).getStartTime()) != -1 && gui.et.compareTime(toSearch.get(i).getEndTime()) == -1){
                        matches[i] = true;
                    }
                    else{
                        matches[i] = false;
                    }
                }
                else{
                    i = toSearch.size();
                }
            }
        }
        else{
            for(int i = 0; i < toSearch.size(); i++){
                if(!toSearch.get(i).isNull()){
                    if(gui.st.compareTime(toSearch.get(i).getStartTime()) != -1 && gui.et.compareTime(toSearch.get(i).getEndTime()) == -1){
                        matches[i] = true;
                    }
                    else{
                        matches[i] = false;
                    }
                }
            }
        }
        Activity a = null;
        if(gui.type.equals("Home")){
            a = new HomeActivity();
        }
        else if(gui.type.equals("School")){
            a = new SchoolActivity();
        }
        else if(gui.type.equals("Other")){
            a = new OtherActivity();
        }
        
        if(!gui.type.equals("")){
            for(int i = 0; i < toSearch.size(); i++){
                
                if(!toSearch.get(i).isNull()){
                    if(gui.type.equals("Home")){
                        
                        if(toSearch.get(i).getClass() == (HomeActivity.class)){
                            
                            matches[i] = true;
                        }
                        else{
                            matches[i] = false;
                        }
                    }
                    if(gui.type.equals("School")){
                        if(toSearch.get(i).getClass() == SchoolActivity.class){
                            matches[i] = true;
                        }
                        else{
                            matches[i] = false;
                        }
                    }
                    if(gui.type.equals("Other")){
                        if(toSearch.get(i).getClass() == OtherActivity.class){
                            matches[i] = true;
                        }
                        else{
                            matches[i] = false;
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < matches.length; i++){
            if(matches[i]){
                gui.txtMessage.append(toSearch.get(i).toString() + "\n");
            }
        }
    }
    
    /**
     * Used to initialize start times for activities, setting values for each attribute.
     * @return the time created or null if troubles occurred when initializing.
     */
    public static Time createStartTime(){
        
        int year = -1, month = -1, day = -1, hour = -1, minute = -1;
        int error = 0;
        Time newTime;
        
        try{
            year = Integer.parseInt(gui.txtSYear.getText());
            if(year < 0){
                JOptionPane.showMessageDialog(gui, "Starting year is negative!");
                error++;
            }
        }catch (Exception e){
            JOptionPane.showMessageDialog(gui, "Starting year is incorrect!");
            error++;
        }
        
        try{
            month = Integer.parseInt(gui.txtSMonth.getText());
            if(month < 1 || month > 12){
                JOptionPane.showMessageDialog(gui, "Starting month is out of range!");
                error++;
            }
        }catch (Exception e){
            JOptionPane.showMessageDialog(gui, "Starting month is incorrect!");
            error++;
        }
        
        try{
            day = Integer.parseInt(gui.txtSDay.getText());
            if(day < 1 || day > 31){
                JOptionPane.showMessageDialog(gui, "Starting day is out of range!");
                error++;
            }
        }catch (Exception e){
            JOptionPane.showMessageDialog(gui, "Starting day is incorrect!");
            error++;
        }
        
        try{
            hour = Integer.parseInt(gui.txtSHour.getText());
            if(hour < 0 || hour > 23){
                JOptionPane.showMessageDialog(gui, "Starting hour is out of range!");
                error++;
            }
        }catch (Exception e){
            JOptionPane.showMessageDialog(gui, "Starting hour is incorrect!");
            error++;
        }
        
        try{
            minute = Integer.parseInt(gui.txtSMin.getText());
            if(minute < 0 || minute > 59){
                JOptionPane.showMessageDialog(gui, "Starting minute is out of range!");
                error++;
            }
        }catch (Exception e){
            JOptionPane.showMessageDialog(gui, "Starting minute is incorrect!");
            error++;
        }
        
        newTime = new Time(year, month, day, hour, minute);
        
        if(error == 0){
            return newTime;
        }
        else{
            gui.txtMessage.append(error + " corrections must be made to starting time.\n");
            return null;
        }
        
    }
    
    /**
     * Used to initialize end times for activities, setting values for each attribute.
     * @return the time created or null if troubles occurred when initializing.
     */
    public static Time createEndTime(){
        
        int year = -1, month = -1, day = -1, hour = -1, minute = -1;
        int error = 0;
        Time newTime;
        
        try{
            year = Integer.parseInt(gui.txtEYear.getText());
            if(year < 0){
                JOptionPane.showMessageDialog(gui, "Ending year is negative!");
                error++;
            }
        }catch (Exception e){
            JOptionPane.showMessageDialog(gui, "Ending year is incorrect!");
            error++;
        }
        
        try{
            month = Integer.parseInt(gui.txtEMonth.getText());
            if(month < 1 || month > 12){
                JOptionPane.showMessageDialog(gui, "Ending month is out of range!");
                error++;
            }
        }catch (Exception e){
            JOptionPane.showMessageDialog(gui, "Ending month is incorrect!");
            error++;
        }
        
        try{
            day = Integer.parseInt(gui.txtEDay.getText());
            if(day < 1 || day > 31){
                JOptionPane.showMessageDialog(gui, "Ending day is out of range!");
                error++;
            }
        }catch (Exception e){
            JOptionPane.showMessageDialog(gui, "Ending day is incorrect!");
            error++;
        }
        
        try{
            hour = Integer.parseInt(gui.txtEHour.getText());
            if(hour < 0 || hour > 23){
                JOptionPane.showMessageDialog(gui, "Ending hour is out of range!");
                error++;
            }
        }catch (Exception e){
            JOptionPane.showMessageDialog(gui, "Ending hour is incorrect!");
            error++;
        }
        
        try{
            minute = Integer.parseInt(gui.txtEMin.getText());
            if(minute < 0 || minute > 59){
                JOptionPane.showMessageDialog(gui, "Ending minute is out of range!");
                error++;
            }
        }catch (Exception e){
            JOptionPane.showMessageDialog(gui, "Ending minute is incorrect!");
            error++;
        }
        
        newTime = new Time(year, month, day, hour, minute);
        
        if(error == 0){
            return newTime;
        }
        else{
            gui.txtMessage.append(error + " corrections must be made to ending time.\n");
            return null;
        }
        
    }
    
    /**
     * createList
     * used to take input from a file, parse through lines
     * and create an array list based on the contents of the file.
     * @param infile string that takes in the name of the input file for parsing
     * @return the filled array list from the input file.
     * @throws IOException 
     */
    public static ArrayList<Activity> createList(String infile) throws IOException{
        
        int i = 0;
        ArrayList<Activity> list = new ArrayList<>(MAX_ACTIVITIES * 3);
        String type, title, start, end, comment, location;
        
        try{
                BufferedReader br = new BufferedReader(new FileReader("files/" + infile));
                String line, info[];
                line = br.readLine();
                while(line != null){
                    info = line.split("\"");
                    if(info[0].equals("type = ")){
                        type = info[1];
                        switch (type) {
                            case "home":
                                list.add(new HomeActivity());
                                break;
                            case "school":
                                list.add(new SchoolActivity());
                                break;
                            case "other":
                                list.add(new OtherActivity());
                                break;
                        }
                    }
                    else if(info[0].equals("title = ")){
                        title = info[1];
                        list.get(i).setTitle(title);
                    }
                    else if(info[0].equals("start = ")){
                        start = info[1];
                        String [] timeStr = start.split(",");
                        list.get(i).setStartTime(new Time(Integer.parseInt(timeStr[0]), Integer.parseInt(timeStr[1]), Integer.parseInt(timeStr[2]), Integer.parseInt(timeStr[3]), Integer.parseInt(timeStr[4])));
                    }
                    else if(info[0].equals("end = ")){
                        end = info[1];
                        String [] timeStr = end.split(",");
                        list.get(i).setEndTime(new Time(Integer.parseInt(timeStr[0]), Integer.parseInt(timeStr[1]), Integer.parseInt(timeStr[2]), Integer.parseInt(timeStr[3]), Integer.parseInt(timeStr[4])));

                    }
                    else if(info[0].equals("comment = ")){
                        comment = info[1];
                        list.get(i).setComment(comment);
                    }
                    else if(info[0].equals("location = ")){
                        location = info[1];
                        list.get(i).setLocation(location);
                    }
                    else{
                        i++;
                    }
                    line = br.readLine();
                }
                
                br.close();
            }catch(FileNotFoundException ex){
                System.out.println("Could not find the " + infile + " input file.");
            }
        
        
        return list;
    }
    
    
    /**
     * writeList
     * Takes the array list of activities and writes each field line by line.
     * @param outfile the name of the string used to write to file.
     * @param list the activity list used to get all required fields for the output file.
     */
    public static void writeList(String outfile, ArrayList<Activity> list){
        
        try {
            PrintWriter output = new PrintWriter(new FileOutputStream("files/" + outfile));
            String typeStr;
            for(int i = 0; i < list.size(); i++){
                if(!list.get(i).isNull()){
                    
                    if(list.get(i).getClass() == HomeActivity.class){
                        typeStr = "home";
                    }
                    else if(list.get(i).getClass() == SchoolActivity.class){
                        typeStr = "school";
                    }
                    else{
                        typeStr = "other";
                    }
                    output.println("type = \"" + typeStr + "\"");
                    output.println("title = \"" + list.get(i).getTitle() + "\"");
                    output.println("start = \"" + list.get(i).getStartTime().year + "," + list.get(i).getStartTime().month + "," + list.get(i).getStartTime().day + "," + list.get(i).getStartTime().hour + "," + list.get(i).getStartTime().minute + "\"");
                    output.println("end = \"" + list.get(i).getEndTime().year + "," + list.get(i).getEndTime().month + "," + list.get(i).getEndTime().day + "," + list.get(i).getEndTime().hour + "," + list.get(i).getEndTime().minute + "\"");                    
                    if(list.get(i).getClass() == OtherActivity.class){
                        output.println("location = \"" + list.get(i).getLocation() + "\"");
                    }
                    output.println("comment = \"" + list.get(i).getComment() + "\"");
                    output.println("----------");
                }
                else{
                    i = list.size();
                }
            }
            output.close();
        } catch (FileNotFoundException ex) {
            Logger.getLogger(DayPlanner.class.getName()).log(Level.SEVERE, null, ex);
            System.out.println("Could not print to selected file.");
        }
        
    }
}
