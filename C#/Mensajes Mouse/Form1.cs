using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Mensajes_Mouse
{
    public partial class Form1 : Form
    {
        string cad;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            cad = "Mouse abajo";
            label1.Visible = false;
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e){
            Point punto = e.Location;
            //MessageBox.Show(cad); 
            label1.Visible = true;
            label1.Location = punto;
            label1.Text = cad;
            
           
        }

        private void button1_MouseLeave(object sender, EventArgs e)
        {
            textBox1.Text = "Haaaaaa!!";
        }
    }
}
