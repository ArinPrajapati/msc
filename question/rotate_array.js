function Rotation(arr, k, direction = "left") {
  let n = arr.length
  if (direction == "left") {
    return arr.slice(k).concat(arr.slice(0, k))
  } else if (direction == "right") {
    return arr.slice(n - k).concat(arr.slice(0, n - k))
  }
}



console.log(Rotation([3, 2, 5, 3, 4], 6, "right"))
