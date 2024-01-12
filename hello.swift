class OldStudent {
  var studentFee = 800
  var Fee : Int {
    return studentFee
  }
}

class NewStudent: OldStudent {
  var amount = 1000
  override var Fee : Int {
    return super.Fee + amount
  }
}

func Hi() -> Int {
  let newstudent = NewStudent()
  return newstudent.Fee
}

func Ho() -> Int {
  let newstudent = NewStudent()
  return newstudent.amount
}
