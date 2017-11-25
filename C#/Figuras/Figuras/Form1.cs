using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Figuras{
    public partial class Form1 : Form{
        private Point p1, p2, p3;
        private Graphics g;
        private Pen pen;
        private SolidBrush brush;
        private int opcion;
        private int ancho, alto;
        private AdjustableArrowCap flechota;

        public Form1(){
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e){
            g = CreateGraphics();
            brush = new SolidBrush(Color.Red);
            pen = new Pen(brush, 5);
            opcion = 0;
            flechota = new AdjustableArrowCap(5, 5);
        }

        #region Rutinas mouse

        private void Form1_MouseDown(object sender, MouseEventArgs e){
            p1 = e.Location;
            //p3 = e.Location;
        }
        private void Form1_MouseUp(object sender, MouseEventArgs e){
            p2 = e.Location;
            
            //Point t;
            int t;
            if(p2.X < p1.X){
                t = p1.X;
                p1.X = p2.X;
                p2.X = t;
            }
            if (p2.Y < p1.Y)
            {
                t = p1.Y;
                p1.Y = p2.Y;
                p2.Y = t;
            }
            ancho = Math.Abs(p2.X - p1.X);
            alto = Math.Abs(p2.Y - p1.Y);
            Form1_Paint(this, null);
        }

        #endregion

        private void Form1_Paint(object sender, PaintEventArgs e){
            int t;
            switch(opcion){
                case 1:
                    toolStripTextBox1.Text = "Rectangle";
                    
                    g.DrawRectangle(pen, p1.X, p1.Y, ancho, alto);
                    //g.DrawString("Rectangle", new Font("Consolas", 20), brush, p1);
                    break;
                case 2:
                    toolStripTextBox1.Text = "Ellipse";
                    g.DrawEllipse(pen, p1.X, p1.Y, ancho, alto);
                    //g.DrawString("Ellipse", new Font("Consolas", 20), brush, p1);
                    break;
                case 3:
                    toolStripTextBox1.Text = "Line";

                    g.DrawLine(pen, p1, p2);
                    //pen.CustomEndCap.WidthScale = 5;
                    
                    pen.CustomEndCap = new AdjustableArrowCap(pen.Width, pen.Width);
                    //pen.EndCap = System.Drawing.Drawing2D.LineCap.ArrowAnchor;
                    
                    //g.DrawString("Line", new Font("Consolas", 20), brush, p1);
                    break;
            }
        }


        private void Shapes_Clicked(object sender, ToolStripItemClickedEventArgs e){
            
            switch (e.ClickedItem.AccessibleName){
                case "Rectangle":
                    opcion = 1;
                    break;
                case "Ellipse":
                    opcion = 2;
                    break;
                case "Line":
                    opcion = 3;
                    break;
            }
            Form1_Paint(this, null);
        }

        private void Color_Clicked(object sender, ToolStripItemClickedEventArgs e)
        {
            switch(e.ClickedItem.AccessibleName){
                case "Red":
                    pen.Color = Color.Red;
                    toolStripTextBox1.ForeColor = Color.Red;
                    break;
                case "Green":
                    pen.Color = Color.Green;
                    toolStripTextBox1.ForeColor = Color.Green;
                    break;
                case "Blue":
                    pen.Color = Color.Blue;
                    toolStripTextBox1.ForeColor = Color.Blue;
                    break;

            }
        }

        private void Width_Clicked(object sender, ToolStripItemClickedEventArgs e){
            switch (e.ClickedItem.AccessibleName){
                case "1":
                    pen.Width = 1;
                    break;
                case "3":
                    pen.Width = 3;
                    break;
                case "5":
                    pen.Width = 5;
                    break;
            }
        }


    }
}
