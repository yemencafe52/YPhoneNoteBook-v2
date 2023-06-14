using System.Windows.Forms;

namespace YPhoneNoteBookUI
{
    public partial class FrmPersonMGR : Form
    {
        private bool success;

        public bool Success
        {
            get { return success; }
        }
        public FrmPersonMGR()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, System.EventArgs e)
        {
            if (!(new YPhoneNoteBookCoreLibW.CPersonControllerW(Constants.ConnectionString).Add(new YPhoneNoteBookCoreLibW.PersonW(0, textBox1.Text, textBox2.Text))))
            {
                MessageBox.Show("OOPS, SOMETHING WENT WRONG :("); return;
            }


            success = true;
            this.Close();
        }
    }
}
