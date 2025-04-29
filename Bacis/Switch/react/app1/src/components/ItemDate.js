import './ItemDate.css'
function ItemDate(){
    const day=15;
  const month="August";
  const year=1947;
    return(
        <div className='mfg-date'>
            <span>{day}</span>
            <span>{month}</span>
            <span>{year}</span>
        </div>
    
    )
}
export default ItemDate;