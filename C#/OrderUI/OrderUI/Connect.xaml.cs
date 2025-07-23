﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace OrderUI
{
    /// <summary>
    /// Connect.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Connect : Window
    {
        public Connect()
        {
            InitializeComponent();
        }

        private void ConnectButton_Click(object sender, RoutedEventArgs e)
        {
            string ip = IpTextBox.Text.Trim();
            int port = 3333;

            try
            {

                var mainWindow = new MainWindow(ip);
                mainWindow.Show();

                this.Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show($"서버 연결 실패: {ex.Message}\n프로그램을 종료합니다.");
                Application.Current.Shutdown();
            }
        }
    }
}
