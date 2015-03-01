/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.*;
import javax.swing.border.*;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;
import javax.swing.filechooser.FileNameExtensionFilter;

/**
 *
 * @author deonn95
 */
public class Dialogc extends JFrame implements ActionListener{

    public static final int WIDTH = 800;
    public static final int HEIGHT = 600;
    public static final int BTNWIDTH = 100;
    public static final int BTNHEIGHT = 30;
    
    private JPanel panel;
    private JMenuBar bar;
    
    private JMenu menuFile;
    private JMenuItem jitNew;
    private JMenuItem jitOpen;
    private JMenuItem jitSave;
    private JMenuItem jitSaveAs;
    
    private JMenu menuCompile;
    private JMenuItem jitCompile;
    private JMenuItem jitCAR;
    
    private JMenu menuConfig;
    private JMenuItem jitJavaC;
    private JMenuItem jitCompOptions;
    private JMenuItem jitJavaR;
    private JMenuItem jitRunOptions;
    private JMenuItem jitWorking;
    
    private JMenu menuHelp;
    private JMenuItem jitHelp;
    private JMenuItem jitAbout;
    
    private JButton btnNew;
    private JButton btnOpen;
    private JButton btnSave;
    private JButton btnSaveAs;
    private JButton btnCompile;
    private JButton btnStop;
    private JButton btnRun;
    
    private JLabel lblBottom;
    
    private JPanel panelBottom;
    private TitledBorder border;
    private JTextArea txt;
    private JScrollPane scroll;
    
    private String currText;
    private boolean saveSpot, projectOpen, compileSpot;
    private JFileChooser saveFile, runFile;
    
    private JNIlib jni;
    
    public Dialogc(){
		
        panel = new JPanel();
		panel.setSize(WIDTH, HEIGHT);
        panel.setLayout(null);
        
        bar = new JMenuBar();
        bar.setSize(WIDTH, 30);
        
        //File menu
        menuFile = new JMenu("File");
        Action actionNew = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionNew.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_N, KeyEvent.CTRL_DOWN_MASK));
        jitNew = new JMenuItem(actionNew);
        jitNew.setText("New");
        jitNew.addActionListener(this);
        Action actionOpen = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionOpen.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_O, KeyEvent.CTRL_DOWN_MASK));
        jitOpen = new JMenuItem(actionOpen);
        jitOpen.setText("Open");
        jitOpen.addActionListener(this);
        Action actionSave = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionSave.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_S, KeyEvent.CTRL_DOWN_MASK));
        jitSave = new JMenuItem(actionSave);
        jitSave.setText("Save");
        jitSave.addActionListener(this);
        Action actionSaveAs = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionSaveAs.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_S, KeyEvent.SHIFT_DOWN_MASK | KeyEvent.CTRL_DOWN_MASK));
        jitSaveAs = new JMenuItem(actionSaveAs);
        jitSaveAs.setText("Save As");
        jitSaveAs.addActionListener(this);
        menuFile.add(jitNew);
        menuFile.add(jitOpen);
        menuFile.add(jitSave);
        menuFile.add(jitSaveAs);
        
        //Compile Menu
        menuCompile = new JMenu("Compile");
        Action actionCompile = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionCompile.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_C, KeyEvent.CTRL_DOWN_MASK));
        jitCompile = new JMenuItem(actionCompile);
        jitCompile.setText("Compile");
        jitCompile.addActionListener(this);
        Action actionCAR = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionCAR.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_C, KeyEvent.SHIFT_DOWN_MASK | KeyEvent.CTRL_DOWN_MASK));
        jitCAR = new JMenuItem(actionCAR);
        jitCAR.setText("Compile and Run");
        jitCAR.addActionListener(this);
        menuCompile.add(jitCompile);
        menuCompile.add(jitCAR);
        
        //Config menu
        menuConfig = new JMenu("Config");
        Action actionJavaC = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionJavaC.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_J, KeyEvent.CTRL_DOWN_MASK));
        jitJavaC = new JMenuItem(actionJavaC);
        jitJavaC.setText("Java Compiler");
        jitJavaC.addActionListener(this);
        Action actionCompOptions = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionCompOptions.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_P, KeyEvent.CTRL_DOWN_MASK));
        jitCompOptions = new JMenuItem(actionCompOptions);
        jitCompOptions.setText("Compiler Options");
        jitCompOptions.addActionListener(this);
        Action actionJavaR = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionJavaR.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_R, KeyEvent.CTRL_DOWN_MASK));
        jitJavaR = new JMenuItem(actionJavaR);
        jitJavaR.setText("Java Run-Time");
        jitJavaR.addActionListener(this);
        Action actionRunOptions = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionRunOptions.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_R, KeyEvent.SHIFT_DOWN_MASK | KeyEvent.CTRL_DOWN_MASK));
        jitRunOptions = new JMenuItem(actionRunOptions);
        jitRunOptions.setText("Run-time Options");
        jitRunOptions.addActionListener(this);
        Action actionWorking = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionWorking.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_W, KeyEvent.CTRL_DOWN_MASK));
        jitWorking = new JMenuItem(actionWorking);
        jitWorking.setText("W=Working Directory");
        jitWorking.addActionListener(this);
        menuConfig.add(jitJavaC);
        menuConfig.add(jitCompOptions);
        menuConfig.add(jitJavaR);
        menuConfig.add(jitRunOptions);
        menuConfig.add(jitWorking);
        
        //Help menu
        menuHelp = new JMenu("Help");
        Action actionHelp = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionHelp.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_H, KeyEvent.CTRL_DOWN_MASK));
        jitHelp = new JMenuItem(actionHelp);
        jitHelp.setText("Help");
        jitHelp.addActionListener(this);
        Action actionAbout = new AbstractAction(){
            @Override
            public void actionPerformed(ActionEvent e){}
        };
        actionAbout.putValue(AbstractAction.ACCELERATOR_KEY, KeyStroke.getKeyStroke(KeyEvent.VK_A, KeyEvent.CTRL_DOWN_MASK));
        jitAbout = new JMenuItem(actionAbout);
        jitAbout.setText("About");
        jitAbout.addActionListener(this);
        menuHelp.add(jitHelp);
        menuHelp.add(jitAbout);
        
        //adding all menu bars
        bar.add(menuFile);
        bar.add(menuCompile);
        bar.add(menuConfig);
        bar.add(menuHelp);
        
        //buttons
        btnNew = new JButton("New");
        btnNew.setBounds(10, 40, BTNWIDTH, BTNHEIGHT);
        btnNew.addActionListener(this);
        btnOpen = new JButton("Open");
        btnOpen.setBounds(BTNWIDTH + 15, 40, BTNWIDTH, BTNHEIGHT);
        btnOpen.addActionListener(this);
        btnSave = new JButton("Save");
        btnSave.setBounds(BTNWIDTH * 2 + 20, 40, BTNWIDTH, BTNHEIGHT);
        btnSave.addActionListener(this);
        btnSaveAs = new JButton("Save As");
        btnSaveAs.setBounds(BTNWIDTH * 3 + 25, 40, BTNWIDTH, BTNHEIGHT);
        btnSaveAs.addActionListener(this);
        btnCompile = new JButton("Compile");
        btnCompile.setBounds(BTNWIDTH * 4 + 30, 40, BTNWIDTH, BTNHEIGHT);
        btnCompile.addActionListener(this);
        btnStop = new JButton("Stop");
        btnStop.setBounds(BTNWIDTH * 5 + 35, 40, BTNWIDTH, BTNHEIGHT);
        btnStop.addActionListener(this);
        btnRun = new JButton("Run");
        btnRun.setBounds(BTNWIDTH * 6 + 40, 40, BTNWIDTH, BTNHEIGHT);
        btnRun.addActionListener(this);
        
        //labels
        lblBottom = new JLabel("Current Project: Untitled");
        lblBottom.setBounds(0, HEIGHT - 50, WIDTH, 30);
        lblBottom.setHorizontalAlignment(SwingConstants.CENTER);
        lblBottom.setVerticalAlignment(SwingConstants.TOP);
        
        //bottom stuff
        panelBottom = new JPanel();
        panelBottom.setBorder(border = new TitledBorder(new EtchedBorder(), "Untitled"));
        panelBottom.setLayout(null);
        panelBottom.setBounds(0, 50 + BTNHEIGHT, WIDTH - 10, HEIGHT - (BTNHEIGHT + 100));
        
        //text field
        txt = new JTextArea();
        Font f = new Font(Font.MONOSPACED, Font.PLAIN, 14); //used to make the font bigger, so hard to see otherwise.
        txt.setFont(f);
        txt.setBackground(Color.WHITE);
        txt.getDocument().addDocumentListener(new DocumentListener(){

            @Override
            public void insertUpdate(DocumentEvent e) {
                projectOpen = true;
                if(!saveSpot){
                    lblBottom.setText("Current Project: Untitled [modified]" );
                }
                else{
                    lblBottom.setText("Current Project: " + saveFile.getSelectedFile().getName() + " [modified]");
                }
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                projectOpen = true;
                if(!saveSpot){
                    lblBottom.setText("Current Project: Untitled [modified]" );
                }
                else{
                    lblBottom.setText("Current Project: " + saveFile.getSelectedFile().getName() + " [modified]");
                }
            }

            @Override
            public void changedUpdate(DocumentEvent e) {
                projectOpen = true;
                if(!saveSpot){
                    lblBottom.setText("Current Project: Untitled [modified]" );
                }
                else{
                    lblBottom.setText("Current Project: " + saveFile.getSelectedFile().getName() + " [modified]");
                }
            }
            
        });
        scroll = new JScrollPane(txt);
        scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);
        scroll.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        scroll.setBounds(10, 20, 770, 440);        
        
        //Add all the stuff to the panel
        panel.add(bar);
        panel.add(btnNew);
        panel.add(btnOpen);
        panel.add(btnSave);
        panel.add(btnSaveAs);
        panel.add(btnCompile);
        panel.add(btnStop);
        panel.add(btnRun);
        panel.add(lblBottom);
        panel.add(panelBottom);
        panelBottom.add(scroll);
        
        setTitle("Dialogc");
        setSize(WIDTH, HEIGHT);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
        setLocationRelativeTo(null);
        setContentPane(panel);
        setResizable(false);
        
        saveSpot = false;
        projectOpen = false;
        compileSpot = false;
        
        jni = new JNIlib();
        
    }
	
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Dialogc d = new Dialogc();
        
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        
        currText = txt.getText();
        
        if(e.getSource() == jitNew || e.getSource() == btnNew){
            
            createNew();
            
        }
        
        else if(e.getSource() == jitSave || e.getSource() == btnSave){
            
            projectOpen = false;
            
            if(saveSpot){
                save();
            }
            else{
                saveAs();
            }
        }
        
        else if(e.getSource() == jitSaveAs || e.getSource() == btnSaveAs){
            
            projectOpen = false;
            
            saveAs();
          
        }
        
        else if(e.getSource() == jitOpen || e.getSource() == btnOpen){
            open();
		}
        
        else if(e.getSource() == jitCompile || e.getSource() == btnCompile){
            compile();
        }
        
        else if(e.getSource() == jitHelp){
			FileReader reader;
            try {
                reader = new FileReader("README.txt");
                int c = 1;
                String str = "";
                c = reader.read();
                do{
                    str = str + (char) c;
                    c = reader.read();
                }while(c != -1);
                
                JOptionPane.showMessageDialog(null, str, "Help", JOptionPane.INFORMATION_MESSAGE);
                
			} catch (FileNotFoundException ex) {
                Logger.getLogger(Dialogc.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(Dialogc.class.getName()).log(Level.SEVERE, null, ex);
            }
		}
        
        else if(e.getSource() == jitAbout){
            
            JOptionPane.showMessageDialog(null, "This program was written by Deon Naltchadjian\nStudent Number 0832759\nSubmitted on February 13, 2015", "About", JOptionPane.DEFAULT_OPTION);
            
        }
        
        repaint();
    }
    
    
    
    public void save(){
        
        try {
            FileWriter fw;
            if(saveFile.getSelectedFile().toString().contains(".config")){
                fw = new FileWriter(saveFile.getSelectedFile());
            }
            else{
                fw = new FileWriter(saveFile.getSelectedFile()+ ".config");
            }
            fw.write(currText);
            fw.close();
        } catch (IOException ex) {
            Logger.getLogger(Dialogc.class.getName()).log(Level.SEVERE, null, ex);
        }
        saveSpot = true;
        lblBottom.setText("Current Project: " + saveFile.getSelectedFile().getName());
        border.setTitle(saveFile.getSelectedFile().getName());
        
    }
    
    public void saveAs(){
        
        JFileChooser chooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter(".config", "config");
        chooser.setFileFilter(filter);
        int choice = chooser.showSaveDialog(null);
        if(choice == JFileChooser.APPROVE_OPTION){
            saveFile = chooser;
            save();
        }
        
    }
    
    public void open(){
        if(projectOpen){
            int choice = JOptionPane.showConfirmDialog(null, "Would you like to close the file without saving?", "Warning", JOptionPane.YES_NO_CANCEL_OPTION);
            if(choice == JOptionPane.YES_OPTION){
                saveSpot = false;
                projectOpen = true;
                currText = "";
                txt.setText("");
            }
            else if(choice == JOptionPane.NO_OPTION){
                if(saveSpot){
                    save();
                }
                else{
                    saveAs();
                }
                saveSpot = false;
                projectOpen = true;
                currText = "";
                txt.setText("");
            }
        }
            
        JFileChooser chooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter(".config", "config");
        chooser.setFileFilter(filter);
        int choice = chooser.showOpenDialog(null);
        if(choice == JFileChooser.APPROVE_OPTION){
            saveFile = chooser;
            FileReader reader;
            try {
                reader = new FileReader(saveFile.getSelectedFile());
                int c = 1;
                String str = "";
                c = reader.read();
                do{
                    str = str + (char) c;
                    c = reader.read();
                }while(c != -1);
                txt.setText(str);
                border.setTitle(saveFile.getSelectedFile().getName());
                lblBottom.setText("Current Project: " + saveFile.getSelectedFile().getName());
                    
            } catch (FileNotFoundException ex) {
                Logger.getLogger(Dialogc.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(Dialogc.class.getName()).log(Level.SEVERE, null, ex);
            }
            projectOpen = true;
        }
    }
    
    public void createNew(){
        if(projectOpen){
            int choice = JOptionPane.showConfirmDialog(null, "Would you like to close the file without svaing?", "Warning", JOptionPane.YES_NO_CANCEL_OPTION);
            if(choice == JOptionPane.YES_OPTION){
                saveSpot = false;
                projectOpen = true;
                currText = "";
                txt.setText("");
            }
            else if(choice == JOptionPane.NO_OPTION){
                if(saveSpot){
                    save();
                }
                else{
                    saveAs();
                }
                saveSpot = false;
                projectOpen = true;
                currText = "";
                txt.setText("");
            }
        }
        else{
            saveSpot = false;
            projectOpen = true;
            currText = "";
            txt.setText("");
        }
        txt.requestFocus();
        lblBottom.setText("Current Project: Untitled");
        border.setTitle("Untitled");
    }
    
    //called on compile button
    public void compile(){
        int checkfail = jni.PM_create(3);
        if(checkfail == 0){
			System.out.println("Creation of ParameterManager unsuccessful");
		}
		else{
			checkfail = jni.PM_manage("title", 4, 1);
			if(checkfail == 0){
				System.out.println("Managing title unsuccessful");
			}
			jni.PM_manage("fields", 4, 1);
			if(checkfail == 0){
				System.out.println("Managing fields unsuccessful");
			}
			jni.PM_manage("buttons", 4, 1);
			if(checkfail == 0){
				System.out.println("Managing buttons unsuccessful");
			}
			jni.PM_parseFrom(txt.getText(), '#');
			String [] strFields = jni.getValue("fields", 2).split(",");
			System.out.println(jni.getValue("buttons", 3));
			String [] strButtons = jni.getValue("buttons", 3).split(",");
			
			
			//write the barebones java file
			try {
				FileWriter fw;
					JFileChooser chooser = new JFileChooser();
					chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
					chooser.setAcceptAllFileFilterUsed(false);
					int choice = chooser.showOpenDialog(this);
					if(choice == JFileChooser.APPROVE_OPTION){
						runFile = chooser;
						String strTitle = jni.getValue("title", 1);
						fw = new FileWriter(runFile.getCurrentDirectory() + "/" + strTitle + ".java");
						fw.write("import javax.swing.*;");
						fw.write("\nimport java.awt.*;");
						fw.write("\nimport java.awt.event.*;");
						fw.write("\npublic class " + strTitle + " extends JFrame{");
						fw.write("\n\tpublic " + strTitle + "(){");
						fw.write("\n\t\tJPanel panel = new JPanel();");
						fw.write("\n\t\tpanel.setLayout(new BorderLayout());");
						for(int i = 0; i < strFields.length; i++){
							fw.write("\n\t\tJLabel lbl" + strFields[i] + " = new JLabel(\"" + strFields[i] + "\");");
							fw.write("\n\t\tpanel.add(lbl" + strFields[i] + ", BorderLayout.NORTH);");
						}
						for(int i = 0; i < strButtons.length; i++){
							fw.write("\n\t\tJButton btn" + strButtons[i] + " = new JButton(\"" + strButtons[i] + "\");");
							fw.write("\n\t\tpanel.add(btn" + strButtons[i] + ", BorderLayout.CENTER);");
							//fw.write("\n\t\tbtn" + strButtons[i] + ".addActionListener(new AbstractAction"
						}
						
						fw.write("\n\t\tsetTitle(\"" + strTitle + "\");");
						fw.write("\n\t\tsetSize(" + WIDTH + ", " + HEIGHT + ");");
						fw.write("\n\t\tsetDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);");
						fw.write("\n\t\tsetLocationRelativeTo(null);");
						fw.write("\n\t\tsetResizable(false);");
						fw.write("\n\t\tsetContentPane(panel);");
						fw.write("\n\t\tsetVisible(true);");
						fw.write("\n\t}");
						fw.write("\n\tpublic static void main (String [] args){");
						fw.write("\n\t\t" + strTitle + " o = new " + strTitle + "();");
						fw.write("\n\t}\n}");
						fw.close();
						Runtime.getRuntime().exec("javac " + strTitle + ".java");
						Runtime.getRuntime().exec("java " + strTitle);
					
				}
				
			} catch (FileNotFoundException ex) {
                Logger.getLogger(Dialogc.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
				Logger.getLogger(Dialogc.class.getName()).log(Level.SEVERE, null, ex);
			}  
			
			/*jni.PM_destroy();*/
		}
    }
    
    public void run(){
        
    }
    
}
