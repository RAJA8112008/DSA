import logo from './logo.svg';
import './App.css';
import Item from './components/Item';
import ItemDate from './components/ItemDate';
function App() {
  return ( 
    <div className='mfg-Date'>
      <Item name="Nirma"></Item>
      <ItemDate day="15" month="August" year="1947"></ItemDate>
      <Item name="Surfexcell"></Item>
      <ItemDate day="23" month="May" year="1987"></ItemDate>
      <Item name="555"></Item>
      <ItemDate day="16" month="September" year="1957"></ItemDate>
      <div className="App">hello ji</div>
    </div> 
  );
}
export default App;