import logo from './logo.svg';
import './App.css';
import Item from './components/Item';
import ItemDate from './components/ItemDate';
function App() {
  const responce=[
    {
      ItemName:"nirma1",
      ItemDay:"28",
      ItemMonth:"june",
      ItemYear:"2008"

    },
    {
      ItemName:"nirma2",
      ItemDay:"281",
      ItemMonth:"juney",
      ItemYear:"2008"

    },
    {
      ItemName:"nirma3",
      ItemDay:"285",
      ItemMonth:"junek",
      ItemYear:"2008"

    }
  ];
  return ( 
    <div className='mfg-Date'>
      <Item name={responce[0].ItemName}></Item>
      <ItemDate day={responce[0].ItemDay} month={responce[0].ItemMonth} year={responce[0].ItemYear}></ItemDate>
      <Item name={responce[1].ItemName}></Item>
      <ItemDate day={responce[1].ItemDay} month={responce[1].ItemMonth} year={responce[1].ItemYear}></ItemDate>
      <Item name={responce[2].ItemName}></Item>
      <ItemDate day={responce[2].ItemDay} month={responce[2].ItemMonth} year={responce[2].ItemYear}></ItemDate>
      <div className="App">hello ji</div>
      <Button ></Button>
    </div> 
  );
}
export default App;