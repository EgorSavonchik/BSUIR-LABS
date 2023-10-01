namespace WEB_153501_Savonchik.Domain.Entities
{
    public class Telephone
    {
        public int Id { set; get; }
        public string Name { set; get; }
        public string Description { set; get; }
        public int FirmId { set; get; }
        public int Price { set; get; }
        public string? ImageSource { set; get; }
        public string? Mime { set; get; }
    }
}