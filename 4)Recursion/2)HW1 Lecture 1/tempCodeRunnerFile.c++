// FIND THE NUMBER OF OCCURENCES OF KEY
int FindElement(int arr[], int h, int key,int &count)
{
    if(arr[h]==key)
    {
        count++;
    }
    if(h >= sizeof(arr) / sizeof(arr[0]))
    {
        return count;
    }
    int ans=FindElement(arr, h+1, key, count);
    return ans;
}
int main()
{
    cout << "Enter the size of array : ";
    int n;
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cout << "enter element : ";
        cin >> arr[i];
    }
    cout << "enter key to search : ";
    int key;
    cin >> key;
    int count = 0;
    int h = 0;
    cout<<" number of occurence of element is : " << FindElement(arr, h, key, count);
    return 0;
}