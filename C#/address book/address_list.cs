using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ProductEnroll
{
    
    class Product
    {
        static public int cnt = 0;

        public int Id {
            get;
            set;

        }
        public string Name {
            get;
            set;
        }
        public int Price
        {
            get;
            set;
        }
        public Product()
        {
            Id = cnt++;
            Name = "";
            Price = 0;
        }

        public Product(string name, int price)
        {
            Id = cnt++;
            Name = name;
            Price = price;
        }

        public Product(int id, string name, int price)
        {
            Id = id; //id 중복시 처리를 해줘야 할 것 같은데?
            Name = name;
            Price = price;
        }

        public override string ToString() 
        {
            return "Id : " + Id + " Name : " + Name + " Price : " + Price;
        }
    }
    
    class Dao
    {

        public int cnt = 0; 
        public Product[] products;
        private int size = 30;

        public Dao() {
            products = new Product[size];
            cnt = 0;
        }

        public bool Insert(string name, int price)
        {
            cnt++;
            if (cnt > size)
            {
                Console.WriteLine("full!");
                return false;
            }
            else 
            {
                Product p = new Product(name, price);
                products[cnt] = p;
                return true;
            }
        }
        public bool delete(int idx)
        {
            for (int i = idx; i < cnt; i++)
            {
                products[i] = products[i + 1];
            }
            products[cnt] = null;
            cnt--;

            return true;
        }
        public Product SelectByIdx(int idx) 
        {
            Product p = products[idx];
            return p;
        }

        public Product SelectByName(string name)
        {
            Product p = null;
            for (int i = 0; i < cnt; i++) {
                if (products[i].Name == name) {
                    p = products[i];
                    return p;
                }
            }

            return p;
        }

    }
    class Service
    {
        Dao dao = new Dao();

        public void add() 
        {
            Console.Write("name : ");
            string name = Console.ReadLine();
            Console.Write("price : ");
            int price = Convert.ToInt32(Console.ReadLine());
            dao.Insert(name, price);
        }

        public void delete() 
        {
            Console.Write("name : ");
            string name = Console.ReadLine();
            Product p = dao.SelectByName(name);
            if (p == null) {
                Console.WriteLine("주소록에 찾는 이름이 없습니다.");
                return;
            }

            dao.delete(p.Id);
            
        }

        public void update()
        {
            Console.Write("name : ");
            string name = Console.ReadLine();
            Console.Write("price : ");
            int price = Convert.ToInt32(Console.ReadLine());

            Product p = dao.SelectByName(name);
            if (p == null)
            {
                Console.WriteLine("주소록에 찾는 이름이 없습니다.");
                return;
            }

            dao.products[p.Id].Price = price;
        }

        public void read() {
            Console.Write("name : ");
            string name = Console.ReadLine();
            Product p = dao.SelectByName(name);
            if (p == null) {
                Console.WriteLine("주소록에 찾는 이름이 없습니다.");
                return;
            }
            Console.WriteLine(p);
        }

        public void printAll() {
            for (int i = 1; i <= dao.cnt; i++) {
                Console.WriteLine(dao.products[i]);
            }
        }

    }

    internal class Program
    {
        public static void Main(string[] args)
        {
            Service service = new Service();
            string mode;
            bool flag = true;
            Console.WriteLine("수행할 명령을 입력하세요.");


            while (flag) 
            {
                Console.WriteLine("1.추가  2.검색  3.삭제  4.수정  5.전체출력  6.종료 ");
                mode = Console.ReadLine();

                switch (mode) {
                    case "1":
                        service.add();
                        break;
                    case "2":
                        service.read();
                        break;
                    case "3":
                        service.delete();
                        break;
                    case "4":
                        service.update();
                        break;
                    case "5":
                        service.printAll();
                        break;
                    case "6":
                        flag = false;
                        break;

                    default:
                        break;
                }
            }
        }
    }
}
