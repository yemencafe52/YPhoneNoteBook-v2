namespace YPhoneNoteBookUI
{
    using YPhoneNoteBookCoreLibW;

    class Test
    {
        static internal void Test0()
        {
            PersonW p = new PersonW(1, "person3", "123458");
            CPersonControllerW pc = new CPersonControllerW(Constants.ConnectionString);
            pc.Add(p);
        }
    }
}
