/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dayplanner;

import java.awt.event.*;
import java.util.ArrayList;
import javax.swing.*;

/**
 * Extends JFrame to become a window, implements actionlistener to have button commands.
 * @author Deon
 */
public class GUI extends JFrame implements ActionListener{
    
    public static final int WIDTH = 800;
    public static final int HEIGHT = 600;
    
    JPanel panel, panelCmd; //The main panel that has everything
    JPanel panMessage, panButtons, panBody;
    JButton btnReset, btnEnter;
    JLabel lblInit, lblMain, lblType, lblTitle, lblST, lblET, lblLocation, lblComment, lblMessage;
    JMenuBar bar;
    JMenu cmdMenu;
    JMenuItem miAdd, miSearch, miExit;
    JComboBox cmbType;
    JTextField txtTitle, txtSYear, txtSMonth, txtSDay, txtSHour, txtSMin, txtEYear, txtEMonth, txtEDay, txtEHour, txtEMin, txtComment, txtLocation;
    JScrollPane spMessage;
    JTextArea txtMessage;
    
    /**
     * Gui variables to be used by the DayPlanner class.
     */
    Time st = null;
    Time et = null;
    String type = "Home";
    String title = "";
    String comment = "";
    String location = "";
    boolean adding = false, searching = false;
    
    /**
    * hCount used to count how many home activities are being stored.
    * sCount used to count how many school activities are being stored.
    * oCount used to count how many other activities are being stored.
    */
    int hCount = 0, sCount = 0, oCount = 0;
    
    ArrayList<Activity> list;
    String outfile = "";
    
    /**
     * The GUI interface, most code is the overall setup.
     */
    public GUI(){
        
        //Window
        panel = new JPanel();
        bar = new JMenuBar();
        setSize(WIDTH, HEIGHT);
        setResizable(false);
        setTitle("Day Planner");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setJMenuBar(bar);
        setContentPane(panel);
        setVisible(true);
        
        //Menu
        cmdMenu = new JMenu("Command");
        
        miAdd = new JMenuItem("Add", new ImageIcon("images/add.png"));
        miAdd.addActionListener(this);
        cmdMenu.add(miAdd);
        miSearch = new JMenuItem("Search", new ImageIcon("images/search.png"));
        miSearch.addActionListener(this);
        cmdMenu.add(miSearch);
        miExit = new JMenuItem("Exit", new ImageIcon("images/exit.png"));
        miExit.addActionListener(this);
        cmdMenu.add(miExit);
        bar.add(cmdMenu);
        
        //Welcome Message
        lblInit = new JLabel("<html>Welcome to DayPlanner\u2122.<br><br>Choose a Command from the \"Commands\" menu above for adding an activity, searching activities,<br> or quitting the program.</html>");
        lblInit.setBounds(50, 100, WIDTH - 100, HEIGHT / 2);
        lblInit.setVisible(true);
        
        //Main panel additions
        panel.setBounds(0, 20, WIDTH, HEIGHT);
        panel.setLayout(null);
        panel.add(lblInit);
        
        //After init panels
        lblMain = new JLabel("Activities.");
        lblMain.setBounds(10, 0, 200, 25);
        
        lblType = new JLabel("Type:");
        lblType.setBounds(20, 25, 50, 25);
        
        cmbType = new JComboBox(new String[]{"Home", "School", "Other"});
        cmbType.addActionListener(this);
        cmbType.setBounds(75, 25, 100, 25);
        
        lblTitle = new JLabel("Title:");
        lblTitle.setBounds(20, 50, 50, 25);
        
        txtTitle = new JTextField();
        txtTitle.setBounds(75, 50, 200, 25);
        
        lblST = new JLabel("Starting time (year, month, day, hour, minute, hover over each for specifics):");
        lblST.setBounds(20, 75, 500, 25);
        
        txtSYear = new JTextField(">0");
        txtSYear.setBounds(20, 100, 50, 25);
        txtSYear.setToolTipText("Integer over zero");
        
        txtSMonth = new JTextField("1-12");
        txtSMonth.setBounds(80, 100, 50, 25);
        txtSMonth.setToolTipText("Integer between 1 and 12");
        
        txtSDay = new JTextField("1-31");
        txtSDay.setBounds(140, 100, 50, 25);
        txtSDay.setToolTipText("Integer between 1 and 31");
        
        txtSHour = new JTextField("0-23");
        txtSHour.setBounds(200, 100, 50, 25);
        txtSHour.setToolTipText("Integer between 0 and 23");
        
        txtSMin = new JTextField("0-59");
        txtSMin.setBounds(260, 100, 50, 25);
        txtSMin.setToolTipText("Integer between 0 and 59");
        
        lblET = new JLabel("Ending time (year, month, day, hour, minute, hover over each for specifics):");
        lblET.setBounds(20, 125, 500, 25);
        
        txtEYear = new JTextField(">0");
        txtEYear.setBounds(20, 150, 50, 25);
        txtEYear.setToolTipText("Integer over zero");
        
        txtEMonth = new JTextField("1-12");
        txtEMonth.setBounds(80, 150, 50, 25);
        txtEMonth.setToolTipText("Integer between 1 and 12");
        
        txtEDay = new JTextField("1-31");
        txtEDay.setBounds(140, 150, 50, 25);
        txtEDay.setToolTipText("Integer between 1 and 31");
        
        txtEHour = new JTextField("0-23");
        txtEHour.setBounds(200, 150, 50, 25);
        txtEHour.setToolTipText("Integer between 0 and 23");
        
        txtEMin = new JTextField("0-59");
        txtEMin.setBounds(260, 150, 50, 25);
        txtEMin.setToolTipText("Integer between 0 and 59");
        
        lblComment = new JLabel("Comment:");
        lblComment.setBounds(20, 175, 100, 25);
        
        txtComment = new JTextField();
        txtComment.setBounds(125, 180, 200, 25);
        
        lblLocation = new JLabel("Location:");
        lblLocation.setBounds(20, 200, 100, 25);
        lblLocation.setVisible(false);
        
        txtLocation = new JTextField();
        txtLocation.setBounds(125, 205, 200, 25);
        txtLocation.setVisible(false);
        
        panBody = new JPanel();
        panBody.setLayout(null);
        panBody.setBounds(0, 0, WIDTH - 300, HEIGHT - 300);
        panBody.setBorder(BorderFactory.createRaisedBevelBorder());
        panBody.add(lblMain);
        panBody.add(lblType);
        panBody.add(txtTitle);
        panBody.add(txtSYear);
        panBody.add(txtSMonth);
        panBody.add(txtSDay);
        panBody.add(txtSHour);
        panBody.add(txtSMin);
        panBody.add(txtEYear);
        panBody.add(txtEMonth);
        panBody.add(txtEDay);
        panBody.add(txtEHour);
        panBody.add(txtEMin);
        panBody.add(cmbType);
        panBody.add(lblTitle);
        panBody.add(lblST);
        panBody.add(lblET);
        panBody.add(lblComment);
        panBody.add(txtComment);
        panBody.add(lblLocation);
        panBody.add(txtLocation);
        
        //Buttons panel
        panButtons = new JPanel();
        panButtons.setLayout(null);
        panButtons.setBounds(WIDTH - 300, 0, 300, HEIGHT - 300);
        panButtons.setBorder(BorderFactory.createRaisedBevelBorder());
        
        btnReset = new JButton("RESET");
        btnReset.setBounds(100, 100, 100, 30);
        btnReset.addActionListener(this);
        
        btnEnter = new JButton("ENTER");
        btnEnter.setBounds(100, 200, 100, 30);
        btnEnter.addActionListener(this);
        
        panButtons.add(btnReset);
        panButtons.add(btnEnter);
        
        //Message panel
        panMessage = new JPanel();
        panMessage.setLayout(null);
        panMessage.setBounds(0, HEIGHT - 300, WIDTH, HEIGHT - 300);
        
        lblMessage = new JLabel("Message:");
        lblMessage.setBounds(20, 0, 100, 25);
        
        txtMessage = new JTextArea();
        spMessage = new JScrollPane(txtMessage);
        spMessage.setBounds(10, 25, WIDTH - 20, 200);
        spMessage.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        spMessage.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        spMessage.setWheelScrollingEnabled(true);
        
        panMessage.add(lblMessage);
        panMessage.add(spMessage);
        
        //main panel that holds all smaller panels
        panelCmd = new JPanel();
        panelCmd.setBounds(0, 0, WIDTH, HEIGHT);
        panelCmd.setLayout(null);
        panelCmd.add(panBody);
        panelCmd.add(panButtons);
        panelCmd.add(panMessage);
    }

    /**
     * Takes an action from the program and performs corresponding action.
     * @param e the action performed in program.
     */
    @Override
    public void actionPerformed(ActionEvent e) {
    
        /**
         * Exit menu bar item
         * Exits the program.
         */
        if(e.getSource() == miExit){
            int choice = JOptionPane.showConfirmDialog(null, "Are you sure you want to exit Day Planner\u2122?", "Wait!", JOptionPane.YES_NO_OPTION);
            if(choice == 0){ //They choose yes
                if(!outfile.equals("")){
                    DayPlanner.writeList(outfile, list);
                }
                System.exit(0);
            }
        }
        
        /**
         * Add menu bar item
         * adds an activity, using a series of checks.
         */
        if(e.getSource() == miAdd){
            adding = true;
            searching = false;
            setContentPane(panelCmd);
            txtComment.setVisible(true);
            lblComment.setVisible(true);
            lblMain.setText("Adding an Activity:");
            if(cmbType.getItemCount() == 4){ //there is " " in the list for searching
                cmbType.removeItemAt(3);
            }
        }
        if(e.getSource() == miSearch){
            adding = false;
            searching = true;
            setContentPane(panelCmd);
            txtComment.setVisible(false);
            lblComment.setVisible(false);
            txtLocation.setVisible(false);
            lblLocation.setVisible(false);
            lblMain.setText("Searching Activities:");
            if(cmbType.getItemCount() == 3){ //there is " " in the list for searching
                cmbType.addItem("All");
            }
        }
        if(e.getSource() == cmbType){
            type = (String) cmbType.getSelectedItem();
            if(type.equals("Other")){
                if(adding){
                    lblLocation.setVisible(true);
                    txtLocation.setVisible(true);
                }
            }
            else{
                lblLocation.setVisible(false);
                txtLocation.setVisible(false);
            }
        }
        
        if(e.getSource() == btnReset){
            
            txtTitle.setText("");
            txtSYear.setText("");
            txtSMonth.setText("");
            txtSDay.setText("");
            txtSHour.setText("");
            txtSMin.setText("");
            
            txtEYear.setText("");
            txtEMonth.setText("");
            txtEDay.setText("");
            txtEHour.setText("");
            txtEMin.setText("");
            
            txtComment.setText("");
            txtLocation.setText("");
            
            txtMessage.append("Text cleared.\n");
            
        }
        
        if(e.getSource() == btnEnter){
            int errors = 0;            
            title = txtTitle.getText();
            comment = txtComment.getText();
            location = txtLocation.getText();
            
            if(adding){ //adding
                st = DayPlanner.createStartTime();
                et = DayPlanner.createEndTime();
                if(st != null && et != null){
                    if(st.compareTime(et) == -1){
                        st = null;
                        et = null;
                        JOptionPane.showMessageDialog(null, "Your ending time comes before your starting time!");
                        errors++;
                    }
                }
                if(title.equals("")){
                    JOptionPane.showMessageDialog(null, "You entered no title!");
                    errors++;
                }
                if(comment.equals("")){
                    JOptionPane.showMessageDialog(null, "You entered no comment!");
                    errors++;
                }
                
                if(st != null && et != null && errors == 0){
                    if(type.equals("Home")){
                        list.add(DayPlanner.createHome());
                        hCount++;
                    }
                    else if(type.equals("School")){
                        list.add(DayPlanner.createSchool());
                        sCount++;
                    }
                    else{
                        list.add(DayPlanner.createOther());
                        oCount++;
                    }
                    txtMessage.append(type + " activity added, " + list.get(list.size() - 1).toString() + "\n");
                }
                else{
                    txtMessage.append(errors + " non-time corrections must be made.\n");
                }
            }
            
            //If searching
            else{
                if(txtSYear.getText().equals("") && txtSMonth.getText().equals("") && txtSDay.getText().equals("") && txtSHour.getText().equals("") && txtSMin.getText().equals("")){
                    st = new Time(0, 0, 0, 0, 0);
                }
                else{
                    st = DayPlanner.createStartTime();
                }
                if(txtEYear.getText().equals("") && txtEMonth.getText().equals("") && txtEDay.getText().equals("") && txtEHour.getText().equals("") && txtEMin.getText().equals("")){
                    et = new Time(Integer.MAX_VALUE, 12, 31, 23, 59);
                }
                else{
                    et = DayPlanner.createEndTime();
                }
                if(st != null && et != null){
                    DayPlanner.searchActivity(list);
                }
            }
        }
        
    }
    
}
