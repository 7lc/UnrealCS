﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;

namespace UnrealEngine
{
    public partial class AActor
    {
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        static extern void Destroy(IntPtr _this);

        public void Destroy()
        {
            CheckIsValid();
            Destroy(_this.Get());
        }

        public T[] GetComponentsByClass<T>() where T : UObject, new()
        {
            CheckIsValid();
            return MarshalUtil.IntPtrArrayToObjectArray<T>( GetComponentsByClass(_this.Get(),TypeClass<T>()));
        }

        public T GetComponentByClass<T>() where T : UObject, new()
        {
            CheckIsValid();
            return Cast<T>(GetComponentByClass(TypeClass<T>()));
        }
    }
}